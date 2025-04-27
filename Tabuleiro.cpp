#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro() {
    estado = (char **) malloc(SIZE * sizeof(char **));
    for (unsigned i = 0; i < SIZE; ++i) {
        estado[i] = (char *) malloc(SIZE * sizeof(char *));
        for (unsigned j = 0; j < SIZE; ++j) {
            estado[i][j] = ' ';
        }
    }
}

Tabuleiro::~Tabuleiro(){
    for (unsigned i = 0; i < SIZE; ++i) {
        free(estado[i]);
    }
    free(estado);
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