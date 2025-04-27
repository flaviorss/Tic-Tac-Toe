#include <iostream>
#include <vector>

using namespace std;

const char vazio = ' ';
typedef vector<vector<char>> Estado;

void imprimir(const Estado& estado) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << (estado[i][j]);
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

int main(){

    char simbolo;
    Estado estado = {{vazio, vazio, vazio},
                     {vazio, vazio, vazio},
                     {vazio, vazio, vazio}};

    cout << "Bem-vindo ao Jogo da Velha!!!" << endl;
    cout << "Selecione o simbolo de jogo desejado: " << endl;
    cout << "X ou O" << endl << "--> ";
    cin >> simbolo;
    while (simbolo != ('X' || 'x') && simbolo != ('O' || 'o')) {
        cout << "Escolha invalida! Digite X ou O: ";
        cin >> simbolo;
    }

    char ia = (simbolo == ('X' || 'x')) ? 'O' : 'X';

    

    imprimir(estado);

    return 0;
}