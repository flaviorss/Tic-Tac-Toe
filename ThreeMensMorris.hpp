#pragma once
#include <iostream>
#include "Tabuleiro.hpp"
#define MAX_JOGADAS 3

typedef struct {
    bool mover_peca;
    int poiscao_inicial;
    int posicao_final;
} Jogada;

class ThreeMensMorris{
public:
    ThreeMensMorris();
    void definirJogador(char jogador);
    void imprimirTabuleiro();
    bool fazerJogada(Jogada jogada);
    bool podeAdicionarPeca();
    
private: 
    void jogarIA();
    bool _fazerJogada(Jogada jogada, char jogador, int * qtd_jogadas);
    vector<Jogada> listarJogadas();
    Tabuleiro tabuleiro;
    char jogador, IA; 
    int jogadas;
    int jogadas_ia;

};
