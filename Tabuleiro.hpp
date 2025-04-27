#pragma once
#include <iostream>
#include <vector>
#define SIZE 3

using namespace std;

class Tabuleiro {
public: 
    Tabuleiro();
    ~Tabuleiro();
    void print();
    char ** estado;
    char ganhador();
    bool final();
};