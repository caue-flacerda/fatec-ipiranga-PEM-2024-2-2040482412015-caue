/*---------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular            *

*               Prof. Carlos Veríssimo                     *

*----------------------------------------------------------*

* Objetivo do Programa: Modular o código do "Xeque Pastor" *

* Data - 13/08/2024                                        * 

* Autores: Jonathan Batista Bispo; Diego Lopes Sakata; Caue Ferreira Lacerda; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *

*----------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#define I 8
#define J 8
#define K 4

void criarTabuleiro(char tabuleiro[I][J][K])
{
    char temp[I][J][K] = {
        {"PT1", "PC1", "PB1", "PD1", "PR1", "PB2", "PC2", "PT2"}, 
        {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"}, 
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},                 
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},                 
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},                 
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},                
        {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"}, 
        {"BT1", "BC1", "BB1", "BD1", "BR1", "BB2", "BC2", "BT2"}
    };

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            for (int k = 0; k < K; k++) {
                tabuleiro[i][j][k] = temp[i][j][k];
            }
        }
    }
}

void printaTabuleiro(char tabuleiro[I][J][K])
{
    printf("----A---B---C---D---E---F---G---H----\n");
    for (int i = 0; i < I; i++) {
        printf("%i| ",I - i);
        for (int j = 0; j < J; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("|%i",I - i);
        printf("\n");
    }
    printf("----A---B---C---D---E---F---G---H----\n");
}


void moverPeca(char tabuleiro[I][J][K], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna)
{
        strcpy(tabuleiro[destinoLinha][destinoColuna], tabuleiro[origemLinha][origemColuna]);
        strcpy(tabuleiro[origemLinha][origemColuna], "...");
}

int main()
{
    char tabuleiro[I][J][K];
    
    criarTabuleiro(tabuleiro);  
    
    printf("=====================================\n");
    printf("-----------Inicio-do-jogo------------\n");
    printf("=====================================\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 6, 4, 4, 4);
    
    printf("\n\n=====================================\n");
    printf("---------------Turno-1---------------\n");
    printf("=====================================\n");
    printf("\n-----------BRANCAS-JOGAM-e4----------\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 1, 4, 3, 4);
    
    printf("\n------------PRETAS-JOGAM-e5----------\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 7, 5, 4, 2);
    
    printf("\n\n=====================================\n");
    printf("---------------Turno-2---------------\n");
    printf("=====================================\n");
    printf("\n----------BRANCAS-JOGAM-Bc4----------\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 0, 1, 2, 2);
    
    printf("\n-----------PRETAS-JOGAM-Cc6----------\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 7, 3, 5, 5);
    
    printf("\n\n=====================================\n");
    printf("---------------Turno-3---------------\n");
    printf("=====================================\n");
    printf("\n----------BRANCAS-JOGAM-Df3----------\n\n");
    printaTabuleiro(tabuleiro);
    
    moverPeca(tabuleiro, 0, 5, 3, 2);
    
    printf("\n-----------PRETAS-JOGAM-Bc5----------\n\n");
    printaTabuleiro(tabuleiro);
    
   
    printf("\n\n=====================================\n");
    printf("---------Turno-4-(CHECK-MATE)--------\n");
    printf("=====================================\n");
    printf("\n-BRANCAS-JOGAM-Df7-CAPTURANDO-O-PP6!-\n\n");
    moverPeca(tabuleiro, 5, 5, 1, 5);
    printaTabuleiro(tabuleiro);

    return 0;
}
