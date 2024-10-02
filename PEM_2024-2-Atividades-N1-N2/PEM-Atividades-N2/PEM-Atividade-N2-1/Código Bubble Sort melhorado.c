/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Melhorar o código de Bubble Sort apresentado durante a aula      *
* Data - 02/10/2024                                               * 
* Autor: Diego Lopes Sakata; Caue Ferreira; Jonathan Batista; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han*
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Função para imprimir o array
void printArray(int array[], int tamanhoArr) {
    for (int i = 0; i < tamanhoArr; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para realizar a ordenação por bubble Sort
void bubbleSort(int array[], int tamanhoArr) {
    int valor;
    bool troca = false;
    for (int i = 0; i < tamanhoArr-1; i++) {
        
        // Loop interno para comparar e trocar elementos adjacentes
        for (int j = 0; j < tamanhoArr-i-1; j++) {
            
            if (array[j] > array[j+1]) {
                
                // Troca os elementos se estiverem na ordem errada
                valor = array[j];
                array[j] = array[j+1];
                array[j+1] = valor;
                troca = true;
            }
        }
        
        // Se não houve troca, finaliza o código
        if (troca == false) {
            printf("A sequencia ja esta organizada.\n");
            exit(0);
        }
    }
    printf("Array ordenado: \n");
    printArray(array, tamanhoArr);
}

int main() {
    int tamanhoArr;
    printf("Esse programa colocara uma sequencia de numeros em ordem crescente.\n");
    printf("Entre com a quantidade de numeros que tera a sequencia: ");
    
    // Scanf para entrar com o tamanho do array
    scanf("%i",&tamanhoArr);
    
    int array[tamanhoArr];
    
    printf("Escreva uma sequência de números inteiros, separados por espaço: \n");
    
    // Scanf para entrar com os valores do array
    for(int i = 0; i < tamanhoArr; i++){
        scanf(" %d",&array[i]);
    }
    
    printf("Array original: \n");
    printArray(array, tamanhoArr);
    bubbleSort(array, tamanhoArr);
    return 0;
}
