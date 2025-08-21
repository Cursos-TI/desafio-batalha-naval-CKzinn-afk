#include <stdio.h>

int main(){
    //Tabuleiro 
    int tabuleiro[10][10]= {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}
    };
    //Codigo para declarar posição do navio horizontal
        int navioh[3] = {3,3,3};
        int linhah;
        int colunah;

        linhah = 2; colunah = 4;

        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linhah][colunah + i] = 3;
        }
        

    //Codigo para declarar posição do navio da vertical
        int naviov[3] = {3,3,3};
        int linhav;
        int colunav;
        
        linhav = 5; colunav = 7;
        
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linhav + i][colunav] = 3;
        }


    //Codigo para imprimir o tabuleiro com navio na tela
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }






    return 0;
}
