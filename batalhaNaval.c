#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

#define NAVIO 3
#define TAMANHO 3
#define HABILIDADEA 5 // tamanho das matrizes de habilidade size
#define HABILIDADEC 5 // valor que marca área de habilidade no tabuleiro mark

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
        int ok = 1;

    if (colunah + TAMANHO <= COLUNAS){//Declara os limites do tabuleiro na horizontal
        for (int i = 0; i < TAMANHO; i++) if (tabuleiro[linhah][colunah + i] != 0) ok = 0;
        if (ok){
                for (int i = 0; i < TAMANHO; i++) tabuleiro[linhah][colunah + i] = NAVIO;
        } else {
            printf("Aviso: Navio da horizontal nao posicionado por sobreposicao.\n");
        }
     } else{
        printf("Aviso: Navio horizontal extrapola borda.\n");
     } 


    //Codigo para declarar posição do navio da vertical
        int linhav = 5, colunav = 7;
        ok = 1;

    if (linhav + TAMANHO <= LINHAS){//Declara os limites do tabuleiro na vertical
        for (int i = 0; i < TAMANHO; i++) if (tabuleiro[linhav + i][colunav] != 0) ok = 0;
            if (ok)
        {
                for (int j = 0; j < TAMANHO; j++){
                    tabuleiro[linhav + j][colunav] = NAVIO;
                }
             } else {
                    printf("Aviso: Navio da vertical nao posicionado por sobreposicao.\n");
                }
        } else{
         printf("Aviso: Navio vertical extrapola borda.\n");
        }

    //Codigo para declarar posição do navio da diagonal principal
        int linhaDP = 0, colunaDP = 0;
        ok = 1;

            if(linhaDP + TAMANHO <= LINHAS && colunaDP + TAMANHO <= COLUNAS) {
                for (int i = 0; i < TAMANHO; i++) if (tabuleiro[linhaDP + i][colunaDP + i]) ok = 0; 
                    if (ok) {
                        for (int i = 0; i < TAMANHO; i++)
                    tabuleiro[linhaDP + i][colunaDP + i] = NAVIO;
                } else printf("Aviso: navio diagonal principal nao posicionado por sobreposicao.\n");
            } else{
                printf("Aviso: navio diagonal principal extrapola borda.\n");
            }

    //Codigo para declarar posição do navio da diagonal secundaria
        int linhaDS = 0, colunaDS = 9;
        ok = 1;

            if(linhaDS + TAMANHO <= LINHAS && colunaDS - (TAMANHO - 1) >= 0) {
                for (int i = 0; i < TAMANHO; i++) if (tabuleiro[linhaDS + i][colunaDS - i] != 0) ok = 0; if (ok) {
                    for (int i = 0; i < TAMANHO; i++) tabuleiro[linhaDS + i][colunaDS - i] = NAVIO;
                } else {
            printf("Aviso: navio diagonal secundaria nao posicionado por sobreposicao.\n");
        }
    } else {
        printf("Aviso: navio diagonal secundaria extrapola borda.\n");
    }

        //construção das matrizes de habilidade 5x5
        int N = HABILIDADEA;
        int meio = N / 2;
        int raio = meio;

        int cone[HABILIDADEA][HABILIDADEA];
        int cruz[HABILIDADEA][HABILIDADEA];
        int octaedro[HABILIDADEA][HABILIDADEA]; 

        //Preencher 
        for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //Cruz
            if (i == meio || j == meio){
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }

            //Octaedro (losango)
            if ( ( (i - meio) < 0 ? -(i - meio) : (i - meio) ) + 
                 ( (j - meio) < 0 ? -(j - meio) : (j - meio) ) <= raio ){
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }

            //Cone (aponta pra baixo, origem no topo)
            if (i <= meio && ( (j - meio) < 0 ? -(j - meio) : (j - meio) ) <= i ){
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    //--- Aplicar habilidades no tabuleiro ---
    int origemLinha = 4, origemColuna = 4; // posição da origem no tabuleiro
    
    // Aplicando Cruz
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (cruz[i][j] == 1){
                int linhaT = origemLinha + (i - meio);
                int colunaT = origemColuna + (j - meio);

                if (linhaT >= 0 && linhaT < LINHAS && colunaT >= 0 && colunaT < COLUNAS){
                    if (tabuleiro[linhaT][colunaT] == 0) // não sobrescreve navio
                        tabuleiro[linhaT][colunaT] = HABILIDADEC;
                }
            }
        }
    }

        //Aplicando octaedro
    int origemLinhaO = 7, origemColunaO = 2; // posição da origem do octaedro
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if (octaedro[i][j] == 1){
            int linhaT = origemLinhaO + (i - meio);
            int colunaT = origemColunaO + (j - meio);

            if (linhaT >= 0 && linhaT < LINHAS && colunaT >= 0 && colunaT < COLUNAS){
                if (tabuleiro[linhaT][colunaT] == 0) // não sobrescreve navio
                    tabuleiro[linhaT][colunaT] = HABILIDADEC;
            }
        }
    }
}

    //Aplicando cone
    int origemLinhaC = 1, origemColunaC = 8; // posição da origem do cone
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if (cone[i][j] == 1){
            int linhaT = origemLinhaC + (i - meio);
            int colunaT = origemColunaC + (j - meio);

            if (linhaT >= 0 && linhaT < LINHAS && colunaT >= 0 && colunaT < COLUNAS){
                if (tabuleiro[linhaT][colunaT] == 0) // não sobrescreve navio
                    tabuleiro[linhaT][colunaT] = HABILIDADEC;
            }
        }
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
