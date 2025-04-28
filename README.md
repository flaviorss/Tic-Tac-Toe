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
  <li> Cada jogador inicia com 3 peças (sendo 'X' ou 'O'). </li>
  <li> A primeira fase do jogo consiste em colocar as peças no tabuleiro vazio, alternadamente. </li>
  <li> Se após todas as peças estarem colocadas, nenhum jogador vencer, o jogo entra na fase de movimentação. </li>
  <li> Os jogadores podem mover uma de suas peças para uma casa vazia e vizinha (linha, coluna ou diagonal). </li>
  <li> O objetivo do jogo continua sendo formar uma linha de 3 peças alinhadas na horizontal, vertical ou diagonal. </li>
  <li> O jogo termina quando:
  <ul>
    <li> Um dos jogadores formar a linha de peças consecutivas (resultando na vitória de algum jogador). </li>
    <li> O limite máximo de movimentos sem que haja um vencedor for alcançado (resultando em um empate). </li>
  </ul>
  </li>
</ul>

## Sequência do Jogo