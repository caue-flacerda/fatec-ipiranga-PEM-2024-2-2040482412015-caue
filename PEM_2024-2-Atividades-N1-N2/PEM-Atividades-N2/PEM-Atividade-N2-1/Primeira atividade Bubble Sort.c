/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Criar um Bubble Sort e reorganizar um array      *
* Data - 27/09/2024                                            * 
* Autor: Diego Sakata; Jonathan Batista; Caue Ferreira; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han *
*--------------------------------------------------------*/

#include <stdio.h>

void printArray(int sequenciaNumeros[], int n){
    printf("A ordem da sequência númerica ficou: ");
    for(int i = 0; i < n; i++){
        printf("%d ",sequenciaNumeros[i]);
    }
}

void bubbleSort(int sequenciaNumeros[], int n){
    for(int i = 0; i < n - 1; i++){
        int change = 0;
        
        for(int j = 0; j < n - 1; j++){
            if(sequenciaNumeros[j] > sequenciaNumeros[j + 1]){
                int maiorNumero = sequenciaNumeros[j];
                sequenciaNumeros[j] = sequenciaNumeros[j + 1];
                sequenciaNumeros[j + 1] = maiorNumero;
                change++;
            }
        }
        if(change == 0){
            break;
        }
    }
}

int main()
{
    int n;
    
    printf("Esse programa pedirá uma sequencia de numeros e a organizará em ordem crescente.\n");
    printf("Entre com a quantidade de numeros que haverá na sequencia: ");
    scanf("%i",&n);

    int sequenciaNumeros[n];
    
    printf("Agora entre com a sequencia de numeros inteiros. (Separe os numeros com espaços):\n");
    
    for(int i = 0; i < n; i++){
        scanf("%d",&sequenciaNumeros[i]);
    }
    
    printArray(sequenciaNumeros, n);
    
    bubbleSort(sequenciaNumeros, n);
    
    printf("\nOperações realizadas.\n");
    
    printArray(sequenciaNumeros, n);

    return 0;
}