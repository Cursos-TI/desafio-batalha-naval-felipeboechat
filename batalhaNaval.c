#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: Tabuleiro 10x10 com dois navios (um horizontal e um vertical)
// Exibição formatada e alinhada conforme solicitado

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posições dos navios conforme exemplo do usuário
    // Navio horizontal: linha 3 (índice 2), colunas E(4), F(5), G(6)
    int linha_navio_h = 2, coluna_navio_h = 4;
    // Navio vertical: coluna J(9), linhas 7(6), 8(7), 9(8)
    int linha_navio_v = 6, coluna_navio_v = 9;

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_navio_h][coluna_navio_h + i] = VALOR_NAVIO;
    }
    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_navio_v + i][coluna_navio_v] = VALOR_NAVIO;
    }

    // Exibe o tabuleiro formatado e alinhado
    printf("Tabuleiro Batalha Naval\n");
    printf("    "); // Reduzido um espaço para alinhar
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%3c", letra);
    }
    printf("\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d -", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%3d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
