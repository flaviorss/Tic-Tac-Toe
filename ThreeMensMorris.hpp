#pragma once
#include <iostream>
#include "Tabuleiro.hpp"
#define MAX_JOGADAS 3

typedef struct {
    bool mover_peca;
    int poiscao_inicial;
    int posicao_final;
} Jogada;

typedef struct {
    char ganhador;
    int profundidade;
} Status;

class ThreeMensMorris{
public:
    ThreeMensMorris();
    void definirJogador(char jogador);
    void imprimirTabuleiro();
    bool fazerJogada(Jogada jogada);
    bool podeAdicionarPeca();
    bool fim();
    
private: 
    void jogarIA();
    bool _fazerJogada(Jogada jogada, char jogador, int * qtd_jogadas, Tabuleiro &tabuleiro);
    bool _fazerJogada(Jogada jogada, char jogador, Tabuleiro &tabuleiro);
    Status minimax(Tabuleiro tabuleiro, char jogador, int profundidade);
    char _inverterJogador(char atual);
    vector<Jogada> listarJogadas(Tabuleiro &tabuleiro, char jogador, bool adicionar_pecas);
    Tabuleiro tabuleiro;
    char jogador, IA; 
    int jogadas;
    int jogadas_ia;

};
