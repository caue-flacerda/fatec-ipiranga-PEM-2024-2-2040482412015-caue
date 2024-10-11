/*-----------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular              *
*          Prof. Carlos Veríssimo                            *
*------------------------------------------------------------*
* Objetivo do Programa: Melhorar o código de Bubble Sort     *
* apresentado durante a aula                                 *
* Data - 02/10/2024                                          * 
* Autor: Diego Lopes Sakata; Caue Ferreira; Jonathan Batista;* 
* Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *
*---------------------------------------------------------   */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


// Função para imprimir o array
void printArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para realizar a ordenação por bubble Sort
void bubbleSort(int array[], int tamanho, int *quantTroca, int *quantCiclo) {
    bool troca = false;
    for (int i = 0; i < tamanho - 1; i++) {
        
        // Loop interno para comparar e trocar elementos adjacentes
        for (int j = 0; j < tamanho-1-i; j++) {
            
            if (array[j] > array[j+1]) {
                
                // Troca os elementos se estiverem na ordem errada
                int valor = array[j];
                array[j] = array[j+1];
                array[j+1] = valor;
                troca = true;
                (*quantTroca) += 1;
            }
        }
        
        // Se não houve troca, finaliza o código
        if (troca == false) {
            printf("A sequencia ja esta organizada.\n");
            exit(0);
        }
        (*quantCiclo) += 1;
    }

}

int main() {
    
    
    int quantTroca = 0, quantCiclo = 0;
    int array[] = {5, 3, 8, 4, 2,
                   115, 113, 118, 114, 112,
                   125, 123, 128, 124, 122,
                   35, 33, 38, 34, 32,
                   45, 43, 48, 44, 42,
                   55, 53, 58, 54, 52,
                   65, 63, 68, 64, 62,
                   75, 73, 78, 74, 72,
                   85, 83, 88, 84, 82,
                   95, 93, 98, 94, 92,
                   15, 13, 18, 14, 12,
                   25, 23, 28, 24, 22
                   };
    int tam = sizeof(array) / sizeof(int);

    printf("Array original: \n");
    printArray(array, tam);

    clock_t start = clock();
    bubbleSort(array, tam, &quantTroca, &quantCiclo);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: \n");
    printArray(array, tam);

    printf("\nA quantidade de trocas feitas foram: %d\n",quantTroca);
    printf("\nA quantidade de Ciclos foram: %d\n",quantCiclo);
    printf("\nTempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}