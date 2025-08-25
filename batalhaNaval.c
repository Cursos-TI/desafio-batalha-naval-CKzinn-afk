#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define NAVIO 3
#define TAMANHO 3

int main(){
    //Tabuleiro 
    int tabuleiro[LINHAS][COLUNAS];

    //Inicializar tabuleiro com agua
    for (int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = 0;
        }

    }
    //Codigo para declarar posição do navio horizontal
        int linhah = 2, colunah = 4;

    if (colunah + TAMANHO <= COLUNAS){//Declara os limites do tabuleiro na horizontal
        for (int i = 0; i < TAMANHO; i++)
        {
            tabuleiro[linhah][colunah + i] = NAVIO;
        }
    }

    //Codigo para declarar posição do navio da vertical
        int linhav = 5, colunav = 7;
        
    if (linhav + TAMANHO <= LINHAS){//Declara os limites do tabuleiro na vertical
        for (int i = 0; i < TAMANHO; i++)
        {
            tabuleiro[linhav + i][colunav] = NAVIO;
        }
    }

    //Codigo para declarar posição do navio da diagonal principal
        int linhaDP = 0, colunaDP = 0;

            if(linhaDP + TAMANHO <= LINHAS && colunaDP + TAMANHO <= COLUNAS) {
                for (int i = 0; i < TAMANHO; i++) {
                    tabuleiro[linhaDP + i][colunaDP + i] = NAVIO;
                }
            }

    //Codigo para declarar posição do navio da diagonal secundaria
        int linhaDS = 0, colunaDS = 9;

            if(linhaDS + TAMANHO <= LINHAS && colunaDS - (TAMANHO - 1) >= 0) {
                for (int i = 0; i < TAMANHO; i++) {
                    tabuleiro[linhaDS + i][colunaDS - i] = NAVIO;
                }
            }


    //Codigo para imprimir o tabuleiro com navio na tela
        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }






    return 0;
}
