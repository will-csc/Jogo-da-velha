#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

void reset_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%c] ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_winner(char player) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
            reset_board();
        }
    }
    // Verifica diagonais
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
        reset_board();
    }
    return false;
}

bool is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    reset_board();
    return true;
}

void machine_play(char machine, char difficulty) {
    if (difficulty == 'F') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = machine;
                    return;
                }
            }
        }
    } else if (difficulty == 'D') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = machine;
                    return;
                }
            }
        }
    }
}

void play(char player, char machine, char difficulty) {
    bool running = true;
    int x, y;

    while (running) {
        print_board();
        printf("Digite a posicao (linha e coluna, de 0 a 2): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != '-') {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }

        board[x][y] = player;

        if (check_winner(player)) {
            print_board();
            printf("Voce venceu!\n");
            return;
        }

        if (is_board_full()) {
            print_board();
            printf("Empate!\n");
            return;
        }

        machine_play(machine, difficulty);

        if (check_winner(machine)) {
            print_board();
            printf("A maquina venceu!\n");
            return;
        }

        if (is_board_full()) {
            print_board();
            printf("Empate!\n");
            return;
        }
    }
}

void play_again(bool *playing) {
    printf("Deseja jogar novamente? (S/N): ");
    char play;
    scanf(" %c", &play);
    *playing = (play == 'S' || play == 's');
    reset_board();
}

void start() {
    char player, machine, difficulty;

    while (true) {
        reset_board();
        printf("Escolha 'O' ou 'X': ");
        scanf(" %c", &player);

        if (player == 'X' || player == 'O') {
            break;
        }
        printf("Escolha invalida! Tente novamente.\n");
    }

    machine = (player == 'X') ? 'O' : 'X';

    while (true) {
        printf("Escolha a dificuldade (F para Facil, D para Dificil): ");
        scanf(" %c", &difficulty);

        if (difficulty == 'F' || difficulty == 'D') {
            break;
        }
        printf("Dificuldade invalida! Tente novamente.\n");
    }

    bool running = true;
    while (running) {
        play(player, machine, difficulty);
        play_again(&running);
    }
}

int main(void) {
    start();
    return 0;
}
