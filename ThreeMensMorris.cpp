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

bool ThreeMensMorris::fazerJogada(int posicao) {
    if (jogadas < MAX_JOGADAS && posicao >= 0 && posicao < SIZE * SIZE) {
        unsigned linha, coluna;
        linha = posicao / SIZE;
        coluna = posicao % SIZE;
        if (tabuleiro.estado[linha][coluna] != ' ') return false;
        tabuleiro.estado[linha][coluna] = jogador;
        ++jogadas;
        return true;
    }
    return false;
}