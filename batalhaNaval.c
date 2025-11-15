#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool (true/false)

// Desafio Batalha Naval - MateCheck

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10 // Tabuleiro 10x10
#define TAMANHO_NAVIO 3      // Navios de tamanho fixo 3
#define AGUA 0               // Representação para água
#define NAVIO 3              // Representação para navio

int main() {
    // -------------------------------------------------------------------------
    // 1. Inicialização do Tabuleiro
    // -------------------------------------------------------------------------
    
    // Declaração e inicialização da matriz 10x10 com AGUA (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // -------------------------------------------------------------------------
    // 2. Definição das Coordenadas e Posicionamento
    // -------------------------------------------------------------------------

    // Coordenadas e orientação do Navio Horizontal
    int h_linha = 2;
    int h_coluna = 1;
    
    // Coordenadas e orientação do Navio Vertical
    int v_linha = 6;
    int v_coluna = 7;
    
    // Variável de controle para validação
    bool pode_posicionar; 

    printf("--- Batalha Naval - Posicionamento Simplificado ---\n");
    
    // --- Posicionamento do Navio Horizontal (2, 1) ---
    pode_posicionar = true;
    
    // Validação de Limites para Horizontal
    if (h_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO || h_linha < 0 || h_coluna < 0) {
        pode_posicionar = false;
    } 
    
    // Validação de Sobreposição Horizontal (simplificada: verifica se todas as 3 células são AGUA)
    if (pode_posicionar) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[h_linha][h_coluna + j] != AGUA) {
                pode_posicionar = false;
                break;
            }
        }
    }
    
    // Execução do Posicionamento
    if (pode_posicionar) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[h_linha][h_coluna + j] = NAVIO; // Marca com 3
        }
        printf("\n[SUCESSO] Navio Horizontal posicionado em: (%d, %d)\n", h_linha, h_coluna);
    } else {
        printf("\n[FALHA] Navio Horizontal em (%d, %d) nao foi posicionado (Limite ou Sobreposicao).\n", h_linha, h_coluna);
    }

    // --- Posicionamento do Navio Vertical (6, 7) ---
    pode_posicionar = true;
    
    // Validação de Limites para Vertical
    if (v_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || v_linha < 0 || v_coluna < 0) {
        pode_posicionar = false;
    }
    
    // Validação de Sobreposição Vertical
    if (pode_posicionar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[v_linha + i][v_coluna] != AGUA) {
                pode_posicionar = false;
                break;
            }
        }
    }

    // Execução do Posicionamento
    if (pode_posicionar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[v_linha + i][v_coluna] = NAVIO; // Marca com 3
        }
        printf("[SUCESSO] Navio Vertical posicionado em: (%d, %d)\n", v_linha, v_coluna);
    } else {
        printf("[FALHA] Navio Vertical em (%d, %d) nao foi posicionado (Limite ou Sobreposicao).\n", v_linha, v_coluna);
    }

    // -------------------------------------------------------------------------
    // 3. Exibição do Tabuleiro Final
    // -------------------------------------------------------------------------

    printf("\n\n--- TABULEIRO FINAL (%dx%d) ---\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    
    // Cabeçalho das Colunas (índices 0 a 9)
    printf("   "); 
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d", j);
    }
    printf(" (Colunas)\n");
    
    // Corpo do Tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Índice da Linha
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da célula (0 para água, 3 para navio)
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    printf("(Linhas)\n");

    return 0;
}