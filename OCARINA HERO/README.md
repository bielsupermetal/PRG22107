Nome: Gabriel Romero Siqueira dos Santos

Disciplina: Programação Orientada a Objetos 2022/2

Curso: Engenharia Eletrônica

# OCARINA HERO

### DESCRIÇÃO
Ocarina Hero é um jogo que consiste tocar uma música pressionando as notas da ocarina, conforme as notas correm na tablatura. No final da tablatura há uma barra que
determina o tempo exato que a nota deve ser pressionada. O jogador, por sua vez, deve buscar o número máximo de pontuação. 

### OBJETIVO
O objetivo do jogo é pressionar a nota indicada na tablatura em cima da barra que define o tempo exato em que a nota deve ser pressionada, visando o máximo de acertos
para obter uma alta pontuação.

### PONTUAÇÃO
O jogador pontua conforme o número de acertos das notas tocadas, somando 1 ponto por nota. Um multiplicador é acrescentado à pontuação, e aumentado eventualmente (até um máximo de 8), após uma determinada sequência de notas tocadas sem erros. Caso o jogador erre a nota tocada, o multiplicador retorna ao estado inicial da pontuação.

- Estado inicial: pontuação = (nota_correta * 1) + pontuação;
- Sequência de 5 acertos: pontuação = (nota_correta * 2) + pontuação;
- Sequência de 10 acertos: pontuação = (nota_correta * 4) + pontuação;
- Sequência de 20 acertos: pontuação = (nota_correta * 8) + pontuação;
