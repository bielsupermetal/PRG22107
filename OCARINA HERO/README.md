Nome: Gabriel Romero Siqueira dos Santos

Disciplina: Programação Orientada a Objetos 2022/2

Curso: Engenharia Eletrônica

# OCARINA HERO

### DESCRIÇÃO
Ocarina Hero é um jogo que consiste acertar uma sequência de notas aleatórias pressionando as notas da ocarina, conforme, as mesmas, correm na tablatura. No final da tablatura há uma barra que determina o tempo exato que a nota deve ser pressionada. O jogador, por sua vez, deve buscar o número máximo de pontuação. O jogo acaba quando três erros são cometidos.

### OBJETIVO
O objetivo do jogo é garantir a máxima pontuação possível.

### PONTUAÇÃO
O jogador pontua conforme o número de acertos das notas tocadas, somando 1 ponto por nota. Um multiplicador é acrescentado à pontuação, e aumentado eventualmente (até um máximo de 4x), após uma determinada sequência de notas tocadas sem erros. Caso o jogador erre a nota tocada, o multiplicador é zerado novamente.

- Estado inicial: pontuação = (nota_correta * 1) + pontuação;
- Sequência de 10 acertos: pontuação = (nota_correta * 2) + pontuação;
- Sequência de 20 acertos: pontuação = (nota_correta * 3) + pontuação;
- Sequência de 30 (ou mais) acertos: pontuação = (nota_correta * 4) + pontuação;
