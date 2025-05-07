<div align="center"  >
  <h1 align="center" >
    Tic Tac Toe
    <br />
  </h1>
   <img src="https://skillicons.dev/icons?i=cpp" alt="">&nbsp;&nbsp;&nbsp;
   <img src="https://skillicons.dev/icons?i=vscode" alt="">
</div>

## Introdução
O presente repositório contempla a implementação de um projeto em C++ do **Jogo da Velha**, entretanto, com modificações, onde além da tradicinal fase de colocação das peças, após cada jogador realizar três adições, eles também podem mover suas peças no tabuleiro para casas adjacentes. Um padrão semelhante ao clássico jogo **Three Men's Morris**, entretanto utilizando o padrão de tabuleiro do Jogo da Velha. <br/><br/>
O objetivo do projeto é criar uma versão estratégica e dinâmica do jogo, onde um player disputa com a máquina programada para nunca perder, utilizando a técnica de busca **Minimax**. <br/><br/>
O projeto foi desenvolvido para fins de estudo em algoritmos de busca e inteligência artificial aplicada a técnicas de otimização de decisões.

## Descrição do Jogo Modificado
<ul>
  <li> Cada jogador inicia com 3 peças. </li>
  <li> A primeira fase do jogo consiste em colocar as peças no tabuleiro vazio, alternadamente. </li>
  <li> Se após todas as peças estarem colocadas, nenhum jogador vencer, o jogo entra na fase de movimentação. </li>
  <li> Os jogadores podem mover uma de suas peças para uma casa vazia e vizinha (linha, coluna ou diagonal). </li>
  <li> O objetivo do jogo continua sendo formar uma linha de 3 peças alinhadas na horizontal, vertical ou diagonal. </li>
  <li> O jogo termina quando, um dos jogadores formar a linha de peças consecutivas.
  </li>
</ul>

## Sequência de Jogo
<ol>
  <li> Escolha do símbolo de jogo pelo usuário (X ou O).</li>
  <li> Fase de Colocação (turnos alternados): </li>
    <ul>
      <li> Cada jogador adiciona uma peça por turno em uma posição vazia. </li>
      <li> A posição informada deve ser um valor de 1 - 9. </li>
      <li> Após 3 turnos por jogador (total de 6 jogadas), o tabuleiro fica com todas as peças colocadas. </li>
      <li> Se houver um ganhador nesta fase, o jogo termina. </li>
    </ul>
  <li> Fase de Movimentação: </li>
    <ul>
      <li> Os jogadores se alternam para mover uma peça por turno. </li>
      <li> Deve se informar a posição da peça que deseja mover seguido da casa para onde ela vai se deslocar. </li>
      <li> Cada peça só pode se mover para uma casa vizinha livre. </li>
      <li> O jogo verifica a cada movimento se houve vitória. </li>
    </ul>
  <li> O jogo termina quando um jogador alcança o objetivo de formar uma linha de 3 peças alinhadas.</li>

</ol>

## Tecnologias e Ferramentas

- Linguagem: **C++**
- Algoritmo: **Minimax**
- Ambiente de Desenvolvimento: **[VS Code](https://code.visualstudio.com/)**

## Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/flaviorss/Tic-Tac-Toe.git
   cd Tic-Tac-Toe/
2. Execução do Programa:
   ```bash
   g++ main.cpp Tabuleiro.cpp ThreeMensMorris.cpp
   ./a.exe (Windows) ou ./a.out (Linux)

## Autores

Desenvolvido por **[Flávio Santos](https://github.com/flaviorss)** e **[Pedro Gabriel](https://github.com/pedrogabdias)**