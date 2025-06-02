#include <stdio.h>

#define SIZE 3

void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int verificarVencedor(char tabuleiro[SIZE][SIZE]) {
    // Verificar linhas e colunas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return 0;
}

int main() {
    char tabuleiro[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int jogadas = 0;
    char jogador = 'X';
    int linha, coluna;
    int vencedor = 0;

    while (jogadas < SIZE * SIZE && vencedor == 0) {
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %c, escolha uma linha e coluna (1-3): ", jogador);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador;
            jogadas++;
            vencedor = verificarVencedor(tabuleiro);

            if (vencedor == 0) {
                jogador = (jogador == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Movimento inválido. Tente novamente.\n");
        }
    }

    imprimirTabuleiro(tabuleiro);

    if (vencedor != 0) {
        printf("Jogador %c venceu!\n", vencedor);
    } else {
        printf("O jogo terminou empatado!\n");
    }

    return 0;
}
