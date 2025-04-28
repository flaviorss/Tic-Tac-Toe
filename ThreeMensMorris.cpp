#include "ThreeMensMorris.hpp"

ThreeMensMorris::ThreeMensMorris(){
    jogador = ' ';
    jogadas = 0;
}

void ThreeMensMorris::definirJogador(char jogador) {
    if (jogador != ' ') {
        this->jogador = jogador;
        this->IA = jogador == 'X' ? 'O' : 'X';
    } 
}

void ThreeMensMorris::imprimirTabuleiro() {
    tabuleiro.print();
}

bool ThreeMensMorris::podeAdicionarPeca() {
    if (jogadas < MAX_JOGADAS) return true;
    return false;
}

bool ThreeMensMorris::fazerJogada(Jogada jogada) {
    if (_fazerJogada(jogada, this->jogador, &jogadas)) {
        jogarIA();
        return true;
    }
    return false;
}

bool ThreeMensMorris::_fazerJogada(Jogada jogada, char jogador, int * qtd_jogadas) {
    if (jogada.mover_peca) {
        return false;
    } else {
        if (jogada.posicao_final >= 0 && jogada.posicao_final < SIZE * SIZE) {
            unsigned linha, coluna;
            linha = jogada.posicao_final / SIZE;
            coluna = jogada.posicao_final % SIZE;
            if (tabuleiro.estado[linha][coluna] != ' ') return false;
            tabuleiro.estado[linha][coluna] = jogador;
            ++(*qtd_jogadas);
            return true;
        }
        return false;
    }
}

vector<Jogada> ThreeMensMorris::listarJogadas() {
    vector<Jogada> jogadas;
    Jogada jogada;
    if (jogadas_ia < MAX_JOGADAS) {
        jogada.mover_peca = false;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (tabuleiro.estado[i][j] == ' ') {
                    jogada.posicao_final = i * SIZE + j;
                    jogadas.push_back(jogada);
                }
            }
        }
    } else {

    }

    return jogadas;
}

void ThreeMensMorris::jogarIA(){
    vector<Jogada> jogadas = listarJogadas();
    _fazerJogada(jogadas[0], IA, &jogadas_ia);
}