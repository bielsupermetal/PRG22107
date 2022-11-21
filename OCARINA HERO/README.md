Nome: Gabriel Romero Siqueira dos Santos

Disciplina: Programação Orientada a Objetos 2022/2

Curso: Engenharia Eletrônica

# OCARINA HERO

### DESCRIÇÃO
Ocarina Hero é um jogo que consiste tocar três músicas pressionando as notas da ocarina, conforme as notas correm na tablatura. No final da tablatura há uma barra que
determina o tempo exato que a nota deve ser pressionada. O jogador, por sua vez, deve buscar o número máximo de pontuação. O jogo acaba, resultando na derrota do jogador, se 20% das notas forem perdidas. Após uma música ser concluída com sucesso, o jogador avança para a próxima música. Ao concluir as três músicas, o jogo é concluído com êxito. Se a música falhar, o jogador pode dar restart na mesma música para continuar seu progresso.

### OBJETIVO
O objetivo do jogo é concluir as três músicas pressionando as notas, indicadas na tablatura, no momento em que estejam em cima do indicador que define o tempo exato que a nota deve ser pressionada, visando o máximo de acertos, para obter uma alta pontuação, e evitar que o jogo se encerre.

### PONTUAÇÃO
O jogador pontua conforme o número de acertos das notas tocadas, somando 1 ponto por nota. Um multiplicador é acrescentado à pontuação, e aumentado eventualmente (até um máximo de 8), após uma determinada sequência de notas tocadas sem erros. Caso o jogador erre a nota tocada, o multiplicador retorna ao estado inicial da pontuação.

- Estado inicial: pontuação = (nota_correta * 1) + pontuação;
- Sequência de 5 acertos: pontuação = (nota_correta * 2) + pontuação;
- Sequência de 10 acertos: pontuação = (nota_correta * 4) + pontuação;
- Sequência de 20 acertos: pontuação = (nota_correta * 8) + pontuação;
