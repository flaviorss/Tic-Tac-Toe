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
};