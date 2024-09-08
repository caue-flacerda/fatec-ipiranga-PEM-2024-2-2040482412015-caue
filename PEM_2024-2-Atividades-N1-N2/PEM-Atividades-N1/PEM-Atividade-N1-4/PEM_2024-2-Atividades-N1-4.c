/*--------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular *

*          Prof. Carlos Veríssimo                                    *

*--------------------------------------------------------*

* Objetivo do Programa: Criar as jogadas do "Xeque Pastor" no tabuleiro desenvolvido *

* Data - 04/08/2024                                               * 

* Autores: Jonathan Batista Bispo; Diego Lopes Sakata; Caue Ferreira Lacerda; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *

*--------------------------------------------------------*/

#include <stdio.h>

#define I 8
#define J 32
int main()
{
    int linha, coluna;
    char xadrez[I][J];

    for (linha = 0; linha < I; linha++)
    {
        for(coluna = 0; coluna <= J; coluna+=4)
        {
            snprintf(&xadrez[linha][coluna], 4, "   ");
        }
        
    }
    
    snprintf(&xadrez[0][0], 4, "PT1");
    snprintf(&xadrez[0][4], 4, "PC1");
    snprintf(&xadrez[0][8], 4, "PB1");
    snprintf(&xadrez[0][12], 4, "PD1");
    snprintf(&xadrez[0][16], 4, "PR1");
    snprintf(&xadrez[0][20], 4, "PB2");
    snprintf(&xadrez[0][24], 4, "PC2");
    snprintf(&xadrez[0][28], 4, "PT2");

    for(linha = 0; linha < I; linha++)
    {
        snprintf(&xadrez[1][(linha * 4)], 4, "PP%i", (linha + 1));
    }

    snprintf(&xadrez[7][0], 4, "BT1");
    snprintf(&xadrez[7][4], 4, "BC1");
    snprintf(&xadrez[7][8], 4, "BB1");
    snprintf(&xadrez[7][12], 4, "BD1");
    snprintf(&xadrez[7][16], 4, "BR1");
    snprintf(&xadrez[7][20], 4, "BB2");
    snprintf(&xadrez[7][24], 4, "BC2");
    snprintf(&xadrez[7][28], 4, "BT2");

    for(linha = 0; linha < I; linha++)
    {
        snprintf(&xadrez[6][(linha * 4)], 4, "BP%i", (linha + 1));
    }

    int jogo, turn = 8;
    for(jogo = 0; jogo <= turn; jogo++)
    {

        switch (jogo)
        {
        case 0:
            printf("===================================\n");
            printf("----------Inicio-do-jogo-----------\n");
            printf("===================================\n\n");
            break;

        case 1:
            printf("\n\n===================================\n");
            printf("--------------Turno-1--------------\n");
            printf("===================================\n");
            printf("\n----------BRANCAS-JOGAM-e4---------\n\n");
            
            snprintf(&xadrez[6][16], 4, "...");
            snprintf(&xadrez[4][16], 4, "BP5");
            break;
        
        case 2:
            printf("\n-----------PRETAS-JOGAM-e5---------\n\n");
            snprintf(&xadrez[1][16], 4, "...");
            snprintf(&xadrez[3][16], 4, "PP5");
            break;

        case 3:
            printf("\n\n===================================\n");
            printf("--------------Turno-2--------------\n");
            printf("===================================\n");
            printf("\n---------BRANCAS-JOGAM-Bc4---------\n\n");
            snprintf(&xadrez[7][20], 4, "...");
            snprintf(&xadrez[4][8], 4, "BB2");
            break;

        case 4:
            printf("\n----------PRETAS-JOGAM-Cc6---------\n\n");
            snprintf(&xadrez[0][4], 4, "...");
            snprintf(&xadrez[2][8], 4, "PC1");
            break;

        case 5:
            printf("\n\n===================================\n");
            printf("--------------Turno-3--------------\n");
            printf("===================================\n");
            printf("\n---------BRANCAS-JOGAM-Df3---------\n\n");
            snprintf(&xadrez[7][12], 4, "...");
            snprintf(&xadrez[5][20], 4, "BD1");
            break;

        case 6:
            printf("\n----------PRETAS-JOGAM-Bc5---------\n\n");
            snprintf(&xadrez[0][20], 4, "...");
            snprintf(&xadrez[3][8], 4, "PB2");
            break;

        case 7:
            printf("\n\n===================================\n");
            printf("--------Turno-4-(CHECK-MATE)-------\n");
            printf("===================================\n");
            printf("\n-BRANCAS-JOGAM-Df7-CAPTURANDO-O-PP6-\n\n");
            snprintf(&xadrez[5][20], 4, "...");
            snprintf(&xadrez[1][20], 4, "BD1");
            break;

        case 8:
            printf("\n\n===================================\n");
            printf("-------------FIM-DO-JOGO-----------\n");
            printf("===================================\n\n");            

        }
        
        printf("---A---B---C---D---E---F---G---H---");
        for (linha = 0; linha < I; linha++)
        {
            printf("\n%i ", (I - linha));
            for(coluna = 0; coluna < J; coluna+=4)
            {
                printf("%s ", &xadrez[linha][coluna]);
            }
            printf("%i", (I - linha));
        }
        printf("\n---A---B---C---D---E---F---G---H---\n");
    }
    return 0;
}