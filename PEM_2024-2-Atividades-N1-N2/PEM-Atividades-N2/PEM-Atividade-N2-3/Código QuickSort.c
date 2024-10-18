/*-----------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular              *
*          Prof. Carlos Veríssimo                            *
*------------------------------------------------------------*
* Objetivo do Programa: Criar um Código de QuickSort com base no diagrama de blocos apresentado        *
* Data - 17/10/2024                                          * 
* Autor: Diego Lopes Sakata; Jonathan Batista; Vinicius Leon; Caue Ferreira; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *
*---------------------------------------------------------   */

#include <stdio.h>

void troca(int *posicao1, int *posicao2){
    int temp = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = temp;
    
}

int particao(int *arr, int limInf, int limSup){
    int pivo = arr[limSup];
    int ind = (limInf - 1);
    
    for(int j = limInf; j < limSup; j++){
        if(arr[j] <= pivo){
            ind = ind + 1;
            
            troca(&arr[ind], &arr[j]);
        }
    }
    
    troca(&arr[ind + 1], &arr[limSup]);
    return ind + 1;
}

void QuickSort (int *arr, int limInferior, int limSup){
    if(limInferior < limSup){
        int indParticao;
        
        indParticao = particao(arr, limInferior, limSup);
        QuickSort(arr, limInferior, indParticao - 1);
        QuickSort(arr, indParticao + 1, limSup);
    }

}

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {100, 70, 90, 60, 10, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr, n);
    QuickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
