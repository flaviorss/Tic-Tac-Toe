#include "ThreeMensMorris.hpp"

ThreeMensMorris::ThreeMensMorris(){
    jogador = ' ';
    jogadas_ia = jogadas = 0;
}

void ThreeMensMorris::definirJogador(char jogador) {
    if (jogador != ' ') {
        this->jogador = jogador;
        this->IA = jogador == 'X' ? 'O' : 'X';
    } 
}

void ThreeMensMorris::imprimirTabuleiro() {
    tabuleiro.print();
}

bool ThreeMensMorris::podeAdicionarPeca() {
    if (jogadas < MAX_JOGADAS) return true;
    return false;
}

bool ThreeMensMorris::fazerJogada(Jogada jogada) {
    if (_fazerJogada(jogada, this->jogador, &jogadas, this->tabuleiro)) {
        jogarIA();
        return true;
    }
    return false;
}

bool ThreeMensMorris::_fazerJogada(Jogada jogada, char jogador, int * qtd_jogadas, Tabuleiro &tabuleiro) {
    if (jogada.mover_peca) {
        if (tabuleiro.moverPeca(jogada.poiscao_inicial, jogada.posicao_final, jogador)) return true;
        return false;
    } else {
        if (jogada.posicao_final >= 0 && jogada.posicao_final < SIZE * SIZE) {
            unsigned linha, coluna;
            linha = jogada.posicao_final / SIZE;
            coluna = jogada.posicao_final % SIZE;
            if (tabuleiro.estado[linha][coluna] != ' ') return false;
            tabuleiro.estado[linha][coluna] = jogador;
            ++(*qtd_jogadas);
            return true;
        }
        return false;
    }
}

bool ThreeMensMorris::_fazerJogada(Jogada jogada, char jogador, Tabuleiro &tabuleiro) {
    if (jogada.mover_peca) {
        return false;
    } else {
        if (jogada.posicao_final >= 0 && jogada.posicao_final < SIZE * SIZE) {
            unsigned linha, coluna;
            linha = jogada.posicao_final / SIZE;
            coluna = jogada.posicao_final % SIZE;
            if (tabuleiro.estado[linha][coluna] != ' ') return false;
            tabuleiro.estado[linha][coluna] = jogador;
            return true;
        }
        return false;
    }
}

vector<Jogada> ThreeMensMorris::listarJogadas(Tabuleiro &tabuleiro) {
    vector<Jogada> jogadas;
    Jogada jogada;
    if (jogadas_ia < MAX_JOGADAS) {
        jogada.mover_peca = false;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (tabuleiro.estado[i][j] == ' ') {
                    jogada.posicao_final = i * SIZE + j;
                    jogadas.push_back(jogada);
                }
            }
        }
    } else {
        jogada.mover_peca = true;
        for (int origem = 0; origem < SIZE * SIZE; ++origem) {
            unsigned l1 = origem / SIZE;
            unsigned c1 = origem % SIZE;
            if (tabuleiro.estado[l1][c1] == IA) {
                for (int destino = 0; destino < SIZE * SIZE; ++destino) {
                    if (tabuleiro._validaMovimentacao(origem, destino, IA)) {
                        jogada.poiscao_inicial = origem;
                        jogada.posicao_final = destino;
                        jogadas.push_back(jogada);
                    }
                }
            }
        }
    }

    return jogadas;
}

char ThreeMensMorris::minimax(Tabuleiro tabuleiro, char jogador, int profundidade) {
    if (profundidade == 0 || tabuleiro.ganhador() != ' ') {
        return tabuleiro.ganhador();
    }

    char ganhador = '.';

    if (tabuleiro.podeAdicionarPecas(jogador)) {
        vector<Jogada> jogadas = listarJogadas(tabuleiro);

        if (jogadas.empty()) return ' ';
        for (const auto& jogada : jogadas) {
            Tabuleiro novo_tabuleiro(tabuleiro.estado);
            _fazerJogada(jogada, jogador, novo_tabuleiro);
            
            char resultado = minimax(novo_tabuleiro, _inverterJogador(jogador), profundidade - 1);

            if (ganhador == '.') {
                ganhador = resultado;
            } else if (resultado == jogador) {
                ganhador = resultado;
            } else if (ganhador != jogador && resultado != _inverterJogador(jogador)) {
                ganhador = resultado;
            }
        }
    }
    
    return ganhador;
}

void ThreeMensMorris::jogarIA(){
    char ganhador = ' ';
    int indice = -1;
    vector<Jogada> jogadas = listarJogadas(this->tabuleiro);
    if (!jogadas.empty()) {
        Tabuleiro novo_tabuleiro(tabuleiro.estado);
        _fazerJogada(jogadas[0], IA, novo_tabuleiro);
        ganhador = minimax(novo_tabuleiro, IA, 4);
        indice = 0;
    }

    for (unsigned i = 1; i < jogadas.size(); ++i) {
        Tabuleiro novo_tabuleiro(tabuleiro.estado);
        _fazerJogada(jogadas[i], IA, novo_tabuleiro);
        char _ganhador = minimax(novo_tabuleiro, jogador, 4);
        if (_ganhador == IA) {
            indice = i;
            break;
        } else if (_ganhador != jogador) {
            indice = i;
        }
    }

    if (indice != -1 ) _fazerJogada(jogadas[indice], IA, &jogadas_ia, this->tabuleiro);
}

char ThreeMensMorris::_inverterJogador(char atual) {
    if (atual == IA) {
        return this->jogador;
    } else {
        return IA;
    }
}

bool ThreeMensMorris::fim() {
    if (tabuleiro.ganhador() != ' ') {
        return true;
    }
    return false;
}