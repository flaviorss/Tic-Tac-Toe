#include <iostream>
#include <vector>
#include <cstdlib> 
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

    while (!jogo.fim()) {
        Jogada jogada;
        bool jogadaValida = false;
    
        while (!jogadaValida) {
            system("clear"); // Para Linux e Mac
            // system("cls"); // Se for no Windows, descomente esta linha e comente a de cima
    
            jogo.imprimirTabuleiro();
    
            cout << "Informe a posicao da peca que deseja mover (1-9) e a posicao destino (1-9): ";
            cin >> jogada.poiscao_inicial >> jogada.posicao_final;
    
            // Se a entrada falhar (ex: letra), limpar o cin
            if (cin.fail()) {
                cin.clear();
                cin.ignore(255, '\n');
                cout << "Entrada invalida. Digite numeros.\n";
                continue;
            }
    
            // Ajuste para índice de base 0
            jogada.poiscao_inicial -= 1;
            jogada.posicao_final -= 1;
    
            jogada.mover_peca = true;
    
            jogadaValida = jogo.fazerJogada(jogada);
            if (!jogadaValida) {
                cout << "Jogada invalida. Tente novamente.\n";
            }
        }
    }
    jogo.imprimirTabuleiro();

    return 0;
}