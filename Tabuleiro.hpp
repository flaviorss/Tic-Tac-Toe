#pragma once
#include <iostream>
#include <vector>
#define SIZE 3

using namespace std;

class Tabuleiro {
public: 
    vector<vector<char>> estado;

    Tabuleiro();
    Tabuleiro(const vector<vector<char>>& estado);
    void print();
    char ganhador();
    bool final();
    bool podeAdicionarPecas(char jogador);
    bool _validaMovimentacao(int i, int j, char joagdor);
    bool moverPeca(int i, int j, char joagdor);
};