#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro: Tabuleiro 10x10 com quatro navios (2 horizontais/verticais + 2 diagonais)
// Exibição formatada e alinhada conforme solicitado

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int posicao_valida(int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO);
}

// Função para verificar se há sobreposição entre navios
int verificar_sobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int nova_linha, nova_coluna;
        
        switch(direcao) {
            case 0: // Horizontal
                nova_linha = linha;
                nova_coluna = coluna + i;
                break;
            case 1: // Vertical
                nova_linha = linha + i;
                nova_coluna = coluna;
                break;
            case 2: // Diagonal principal (i,i)
                nova_linha = linha + i;
                nova_coluna = coluna + i;
                break;
            case 3: // Diagonal secundária (i,9-i)
                nova_linha = linha + i;
                nova_coluna = coluna - i;
                break;
        }
        
        if (!posicao_valida(nova_linha, nova_coluna) || tabuleiro[nova_linha][nova_coluna] == VALOR_NAVIO) {
            return 1; // Há sobreposição ou posição inválida
        }
    }
    return 0; // Não há sobreposição
}

// Função para posicionar um navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int nova_linha, nova_coluna;
        
        switch(direcao) {
            case 0: // Horizontal
                nova_linha = linha;
                nova_coluna = coluna + i;
                break;
            case 1: // Vertical
                nova_linha = linha + i;
                nova_coluna = coluna;
                break;
            case 2: // Diagonal principal (i,i)
                nova_linha = linha + i;
                nova_coluna = coluna + i;
                break;
            case 3: // Diagonal secundária (i,9-i)
                nova_linha = linha + i;
                nova_coluna = coluna - i;
                break;
        }
        
        tabuleiro[nova_linha][nova_coluna] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posições dos navios conforme exemplo do usuário
    // Navio 1: Horizontal - linha 3, coluna 3
    int linha1 = 2, coluna1 = 3, direcao1 = 0;
    
    // Navio 2: Vertical - linha 7, coluna 9
    int linha2 = 6, coluna2 = 9, direcao2 = 1;
    
    // Navio 3: Diagonal principal - linha 7, coluna 2
    int linha3 = 6, coluna3 = 2, direcao3 = 2;
    
    // Navio 4: Diagonal secundária - linha 7, coluna 8
    int linha4 = 6, coluna4 = 8, direcao4 = 3;

    // Validação e posicionamento dos navios
    if (!verificar_sobreposicao(tabuleiro, linha1, coluna1, direcao1)) {
        posicionar_navio(tabuleiro, linha1, coluna1, direcao1);
    }
    
    if (!verificar_sobreposicao(tabuleiro, linha2, coluna2, direcao2)) {
        posicionar_navio(tabuleiro, linha2, coluna2, direcao2);
    }
    
    if (!verificar_sobreposicao(tabuleiro, linha3, coluna3, direcao3)) {
        posicionar_navio(tabuleiro, linha3, coluna3, direcao3);
    }
    
    if (!verificar_sobreposicao(tabuleiro, linha4, coluna4, direcao4)) {
        posicionar_navio(tabuleiro, linha4, coluna4, direcao4);
    }

    // Exibe o tabuleiro formatado e alinhado
    printf("Tabuleiro Batalha Naval\n");
    printf("   ");
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
