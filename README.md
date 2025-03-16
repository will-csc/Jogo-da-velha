# Jogo da Velha em C

![image](https://github.com/user-attachments/assets/75fc2ddf-8b00-4106-b8ea-29649391cab3)

## Descrição
Este é um jogo da velha implementado em linguagem C. O jogo permite que um jogador jogue contra a máquina, com duas opções de dificuldade:
- **Fácil (F)**: A máquina joga aleatoriamente na primeira posição livre.
- **Difícil (D)**: A máquina joga na primeira posição livre (não implementa estratégias avançadas).

## Como Jogar
1. Compile o programa usando um compilador C, como GCC.
2. Execute o programa.
3. Escolha seu símbolo (X ou O).
4. Escolha a dificuldade (F para Fácil, D para Difícil).
5. Insira as coordenadas da jogada (linha e coluna de 0 a 2).
6. O jogo continuará até que haja um vencedor ou empate.
7. Ao final do jogo, você pode escolher se deseja jogar novamente.

## Compilação e Execução
Para compilar o programa usando GCC:
```sh
gcc main.c -o main
```
Para executar:
```sh
./main
```

## Exemplo de Jogo
```
Escolha 'O' ou 'X': X
Escolha a dificuldade (F para Facil, D para Dificil): D
Digite a posicao (linha e coluna, de 0 a 2): 0 0
[X] [-] [-]
[-] [-] [-]
[-] [-] [-]

A maquina jogou:
[X] [-] [-]
[-] [O] [-]
[-] [-] [-]
```

## Contribuição

Se possuírem contribuições ou melhorias para esse projeto podem entrar em contato comigo (11 969541207).

