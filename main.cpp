#include <iostream>
#include <vector>
#include <cstdlib>
#include "Tabuleiro.hpp"
#include "ThreeMensMorris.hpp"

using namespace std;

int main() {
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

    // Fase de posicionamento
    while (jogo.podeAdicionarPeca()) {
        system("clear");
        jogo.imprimirTabuleiro();

        Jogada jogada;
        jogada.mover_peca = false;

        cout << "Informe a posicao da jogada (1 - 9): ";
        cin >> jogada.posicao_final;
        jogada.posicao_final -= 1;

        while (!jogo.fazerJogada(jogada)) {
            cout << "Jogada Invalida!" << endl << "Informe o numero da jogada (1 - 9): ";
            cin >> jogada.posicao_final;
            jogada.posicao_final -= 1;
        }
    }

    // Fase de movimentação
    while (!jogo.fim()) {
        Jogada jogada;
        bool jogadaValida = false;

        while (!jogadaValida) {
            system("clear");
            jogo.imprimirTabuleiro();

            cout << "Informe a posicao da peca que deseja mover (1 - 9) e a posicao destino (1 - 9): ";
            cin >> jogada.poiscao_inicial >> jogada.posicao_final;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(255, '\n');
                cout << "Entrada invalida. Digite numeros.\n";
                continue;
            }

            jogada.poiscao_inicial -= 1;
            jogada.posicao_final -= 1;
            jogada.mover_peca = true;

            jogadaValida = jogo.fazerJogada(jogada);
            if (!jogadaValida) {
                cout << "Jogada invalida. Tente novamente.\n";
            }
        }
    }

    system("clear");
    jogo.imprimirTabuleiro();

    return 0;
}