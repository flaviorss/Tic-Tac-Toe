#include <iostream>
#include <vector>
#include "Tabuleiro.hpp"
#include "ThreeMensMorris.hpp"

using namespace std;

int main(){
    char simbolo;
    ThreeMensMorris jogo;
    cout << "Bem-vindo ao Jogo da Velha!!!" << endl;
    cout << "Selecione o simbolo de jogo desejado: " << endl;
    cout << "X ou O" << endl << "--> ";
    cin >> simbolo;
    while (simbolo != 'X' && simbolo != 'x' && simbolo != 'O' && simbolo != 'o') {
        cout << "Escolha invalida! Digite X ou O: ";
        cin >> simbolo;
    }

    jogo.definirJogador((simbolo == 'X' || simbolo == 'x') ? 'X' : 'O');
    jogo.imprimirTabuleiro();

    while(jogo.podeAdicionarPeca()){
        Jogada jogada;
        jogada.mover_peca = false;
        cout << "Informe a posicao da jogada (1 - 9): ";
        cin >> jogada.posicao_final;
        jogada.posicao_final -= 1;
        while(!jogo.fazerJogada(jogada)){
            cout << "Jogada Invalida!" << endl << "Informe o numero da jogada (1 - 9): ";
            cin >> jogada.posicao_final;
            jogada.posicao_final -= 1;
        }
        jogo.imprimirTabuleiro();
    }

    

    return 0;
}