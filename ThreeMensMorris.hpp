#pragma once
#include <iostream>
#include "Tabuleiro.hpp"
#define MAX_JOGADAS 3

class ThreeMensMorris{
public:

    ThreeMensMorris();
    void definirJogador(char jogador);
    void imprimirTabuleiro();
    bool fazerJogada(int posicao);
    bool podeAdicionarPeca();
private: 
    Tabuleiro tabuleiro;
    char jogador, IA; 
    unsigned jogadas;

};
