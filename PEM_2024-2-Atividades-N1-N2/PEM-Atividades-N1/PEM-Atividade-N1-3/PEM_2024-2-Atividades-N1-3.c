/*--------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular *

*          Prof. Carlos Veríssimo                                    *

*--------------------------------------------------------*

* Objetivo do Programa: Criar um tabuleiro de xadrez em C      *

* Data - 29/08/2024                                               * 

* Autores: Diego Lopes Sakata; Caue Ferreira Lacerda; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *

*--------------------------------------------------------*/

#include <stdio.h>

int main() {
  int i, cont = 6;
  char peças[8] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
  char num[8] = {'1', '2', '3', ' ', ' ', '6', '7', '8'};

  printf("     A   B   C   D   E   F   G   H\n");
  printf("  -----------------------------------\n");

  printf("8 | ");
  for(i = 0; i < 8; i++){
    printf("P%c%c ", peças[i], num[i]);
      if(i == 7){
        printf("| ");
        printf("\n");
      }
  }
  
  printf("7 | ");
  for(i = 0; i < 8; i++){
    printf("PP%i ",i+1);
      if(i == 7){
        printf("| ");
        printf("\n");
      }
  }
  
  for(i = 0; i < 4; i++){
    printf("%i | ",cont);
    for(int j = 0; j < 8; j++){
      printf(" X  ");
    }
    printf("| ");
    printf("\n");
    cont--;
  }

  printf("2 | ");
  for(i = 0; i < 8; i++){
    printf("BP%i ",i+1);
      if(i == 7){
        printf("| ");
        printf("\n");
      }
  }
  
  printf("1 | ");
  for(i = 0; i < 8; i++){
    printf("B%c%c ", peças[i], num[i]);
      if(i == 7){
        printf("| ");
        printf("\n");
      }
  }
  printf("  -----------------------------------\n");

  return 0;
}