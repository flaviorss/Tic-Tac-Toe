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
        if (!this->fim()) {
            jogarIA();
        }
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
        if (tabuleiro.moverPeca(jogada.poiscao_inicial, jogada.posicao_final, jogador)) return true;
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

vector<Jogada> ThreeMensMorris::listarJogadas(Tabuleiro &tabuleiro, char jogador, bool adicionar_pecas) {
    vector<Jogada> jogadas;
    Jogada jogada;
    if (adicionar_pecas) {
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
            if (tabuleiro.estado[l1][c1] == jogador) {
                for (int destino = 0; destino < SIZE * SIZE; ++destino) {
                    if (tabuleiro._validaMovimentacao(origem, destino, jogador)) {
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

Status ThreeMensMorris::minimax(Tabuleiro tabuleiro, char jogador, int profundidade) {
    Status melhor_jogada;
    if (profundidade == 0 || tabuleiro.ganhador() != ' ') {
        melhor_jogada.ganhador = tabuleiro.ganhador();
        melhor_jogada.profundidade = profundidade;
        return melhor_jogada;
    }

    melhor_jogada.profundidade = -1;

    vector<Jogada> jogadas = listarJogadas(tabuleiro, jogador, tabuleiro.podeAdicionarPecas(jogador));

    for (const auto& jogada : jogadas) {
        Tabuleiro novo_tabuleiro(tabuleiro.estado);
        _fazerJogada(jogada, jogador, novo_tabuleiro);
        
        Status resultado = minimax(novo_tabuleiro, _inverterJogador(jogador), profundidade - 1);

        if (melhor_jogada.profundidade == -1) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
        } else if (melhor_jogada.ganhador == resultado.ganhador && melhor_jogada.profundidade < resultado.profundidade) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
        } else if (melhor_jogada.ganhador != jogador && resultado.ganhador != _inverterJogador(jogador)) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
        }
    }
    
    return melhor_jogada;
}

void ThreeMensMorris::jogarIA(){
    Status melhor_jogada;
    int indice = -1;
    int profundidade = 4;
    melhor_jogada.profundidade = -1;

    vector<Jogada> jogadas = listarJogadas(this->tabuleiro, IA, this->tabuleiro.podeAdicionarPecas(IA));

    for (unsigned i = 0; i < jogadas.size(); ++i) {
        Tabuleiro novo_tabuleiro(tabuleiro.estado);
        _fazerJogada(jogadas[i], IA, novo_tabuleiro);
        Status resultado = minimax(novo_tabuleiro, jogador, profundidade);

        if (melhor_jogada.profundidade == -1) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
            indice = i;
        } else if (melhor_jogada.ganhador == resultado.ganhador && melhor_jogada.profundidade < resultado.profundidade) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
            indice = i;
        } else if (melhor_jogada.ganhador != IA && resultado.ganhador != jogador) {
            melhor_jogada.ganhador = resultado.ganhador;
            melhor_jogada.profundidade = resultado.profundidade;
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