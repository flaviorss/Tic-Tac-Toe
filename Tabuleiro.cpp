#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro() {
    estado = vector<vector<char>>(SIZE, vector<char>(SIZE, ' '));
}

Tabuleiro::Tabuleiro(const vector<vector<char>>& estado) {
    this->estado = estado;
}

void Tabuleiro::print() {
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << (estado[i][j]);
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

char Tabuleiro::ganhador(){
    //Verifica linhas
    for (int i = 0; i < 3; i++) {
        if (estado[i][0] != ' ' && estado[i][0] == estado[i][1] && estado[i][1] == estado[i][2]) {
            return estado[i][0];
        }
    }
    //Verifica colunas
    for (int j = 0; j < 3; j++) {
        if (estado[0][j] != ' ' && estado[0][j] == estado[1][j] && estado[1][j] == estado[2][j]) {
            return estado[0][j];
        }
    }
    //Verifica diagonais
    if (estado[0][0] != ' ' && estado[0][0] == estado[1][1] && estado[1][1] == estado[2][2]) {
        return estado[0][0];
    }
    if (estado[0][2] != ' ' && estado[0][2] == estado[1][1] && estado[1][1] == estado[2][0]) {
        return estado[0][2];
    }

    return ' ';

}

bool Tabuleiro::final(){
    if(ganhador() == 'X'){
        cout << "O jogador X venceu" << endl;
        return true;
    }else if(ganhador() == 'O'){
        cout << "O jogador O venceu" << endl;
        return true;
    }else{
        return false;
    }
}

bool Tabuleiro::podeAdicionarPecas(char jogador) {
    int contador = 0;
    for (unsigned i = 0; i < SIZE; ++i) {
        for (unsigned j = 0; j < SIZE; ++j) {
            if (estado[i][j] == jogador) {
                ++contador;
            }
        }
    }

    if (contador < SIZE) return true;
    return false;
}

bool Tabuleiro::moverPeca(int i, int j, char jogador) {
    if (!_validaMovimentacao(i, j, jogador)) {
        return false; 
    }

    unsigned l1 = i / SIZE;
    unsigned c1 = i % SIZE;
    unsigned l2 = j / SIZE;
    unsigned c2 = j % SIZE;

    estado[l1][c1] = ' ';      
    estado[l2][c2] = jogador;  

    return true;
}

bool Tabuleiro::_validaMovimentacao(int i, int j, char jogador){
    if (i < 0 || i >= SIZE * SIZE || j < 0 || j >= SIZE * SIZE) return false;
    unsigned l1, c1, l2, c2;
    l1 = i / SIZE;
    c1 = i % SIZE;
    l2 = j / SIZE;
    c2 = j % SIZE;

    if (estado[l1][c1] != jogador) return false;
    if (estado[l2][c2] != ' ') return false;

    // Calcula distância entre origem e destino
    int dl = abs((int)l1 - (int)l2);
    int dc = abs((int)c1 - (int)c2);
    
    // Movimento válido: 1 passo para qualquer direção (incluso diagonal)
    if ((dl == 1 && dc == 0) || (dl == 0 && dc == 1) || (dl == 1 && dc == 1)) {
        return true;
    }
    
    return false;
}