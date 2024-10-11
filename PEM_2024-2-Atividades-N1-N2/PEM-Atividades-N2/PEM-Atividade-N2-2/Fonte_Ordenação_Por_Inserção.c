/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: ORDENAÇÃO POR INSERÇÃO  DE COMPARATIVO *
*                                                              *
* Data: 04/10/2024                                             * 
* Autor: Diego Lopes Sakata; Caue Ferreira; Jonathan Batista;  * 
* Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han     *
*--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ordena um array usando o algoritmo de ordenação por inserção
void ordenacaoInsercao(int numeros[], int quantidade, int *quantTroca, int *quantCiclo) {
    for (int i = 1; i < quantidade; i++) {
        int elemento = numeros[i]; // Elemento a ser inserido
        int posicao = i - 1;

        // Move elementos maiores para a direita
        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
            (*quantTroca) += 1;
        }
        numeros[posicao + 1] = elemento; // Insere o elemento na posição correta
        (*quantCiclo) += 1;
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {


    int quantTroca = 0, quantCiclo = 0;
    int numeros[] = {5, 3, 8, 4, 2,
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
    int quantidadeNumeros = sizeof(numeros) / sizeof(int);

    
    printf("Array original: \n");
    imprimirArray(numeros, quantidadeNumeros);

    clock_t start = clock();
    ordenacaoInsercao(numeros, quantidadeNumeros, &quantTroca, &quantCiclo); // Ordena o array
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: \n");
    imprimirArray(numeros, quantidadeNumeros);

    printf("\nA quantidade de trocas feitas foram: %d\n",quantTroca);
    printf("\nA quantidade de Ciclos foram: %d\n",quantCiclo);
    printf("\nTempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}