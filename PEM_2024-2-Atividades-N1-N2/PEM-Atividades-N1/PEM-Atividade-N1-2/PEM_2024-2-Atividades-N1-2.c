/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Calcular a nota final de um candidato para a vaga de estágiario da empresa de TI.      *
* Data - 23/08/2024                                              * 
* Autores: Diego Lopes Sakata, Jonathan Batista Bispo, Matheus Arthur, Diego Silva, Dennis Ramos, Caue Ferreira e Pedro Yun  * 
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, t, cont = 1, loop;
    
    printf("Esse programa calculará a nota final do candidato.\n");
    printf("Quantas categorias diferentes existem?\n");
    printf("R: ");
    scanf("%i",&n);
    
    if(n > 0){
    char **cat = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
            cat[i] = (char *)malloc(100 * sizeof(char)); 
        }
    
    for(i = 0; i < n; i++){
        printf("Digite o nome da %i categoria: ",cont);
        scanf(" %99[^\n]",cat[i]);
        cont++;
    }
    
    int *test = (int *)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++){
        printf("Quantos testes tem na categoria %s: ",cat[i]);
        scanf("%i",&test[i]);
        while(test[i] <= 2){
            printf("O número de testes deve ser maior do que 2.\n");
            printf("Digite novamente o número de testes presente na categoria: ");
            scanf("%i",&test[i]);
        }
    }
    
    float **notas = (float **)malloc(n * sizeof(float *));
    for(i = 0; i < n; i++){
        notas[i] = (float *)malloc(test[i] * sizeof(float));
    }
    
    float *maior = (float *)malloc(n * sizeof(float));
    float *menor = (float *)malloc(n * sizeof(float));
    float *soma = (float *)malloc(n * sizeof(float));
    
    
    for(i = 0; i < n; i++){
        printf("Digite as notas dos testes de %s:\n",cat[i]);
        for(a = 0; a < test[i]; a++){
            scanf("%f",&notas[i][a]);
            if(notas[i][a] < 0 || notas[i][a] > 10){
                printf("As notas devem ser entre 0 e 10.\n");
                printf("Entre novamente com as notas que voce digitou errado: ");
                while(notas[i][a] < 0 || notas[i][a] > 10){
                    scanf("%f",&notas[i][a]);
                }
            }
        }
    }

    printf("Você deseja entrar com mais alguma categoria?");
    printf("\nDigite 1 para sim ou 0 para nao: ");
    scanf("%i",&loop);
    
    while(loop == 1){
        printf("Digite a quantidade de categorias que você deseja entrar: ");
        scanf("%i",&t);
        
        if(t > 0){
            cont = 1;
            
            int b = n;
            n = n + t;
            
            cat = (char **)realloc(cat, n * sizeof(char *));
            for(i = b; i < n; i++){
                cat[i] = (char *)malloc(100 * sizeof(char));
            }
            
            test = (int *)realloc(test, n * sizeof(int));
            notas = (float **)realloc(notas, n * sizeof(float *));
            maior = (float *)realloc(maior, n * sizeof(float));
            menor = (float *)realloc(menor, n * sizeof(float));
            soma = (float *)realloc(soma, n * sizeof(float));
            
            for(i = b; i < n; i++){
                printf("Digite o nome da %i categoria nova: \n",cont);
                scanf(" %99[^\n]",cat[i]);
                cont++;
            }
            
            for(i = b; i < n; i++){
                printf("Digite a quantidade de testes da categoria %s: ",cat[i]);
                scanf("%i",&test[i]);
                while(test[i] <= 2){
                    printf("O número de testes deve ser maior do que 2.\n");
                    printf("Digite novamente o número de testes presente na categoria: ");
                    scanf("%i",&test[i]);
                }
            }
            
            for(i = b; i < n; i++){
                notas[i] = (float *)malloc(test[i] * sizeof(float));
            }

            for(i = b; i < n; i++){
                printf("Digite as notas dos testes de %s:\n",cat[i]);
                for(a = 0; a < test[i]; a++){
                    scanf("%f",&notas[i][a]);
                    if(notas[i][a] < 0 || notas[i][a] > 10){
                        printf("As notas devem ser entre 0 e 10.\n");
                        printf("Entre novamente com as notas que voce digitou errado: ");
                        while(notas[i][a] < 0 || notas[i][a] > 10){
                            scanf("%f",&notas[i][a]);
                        }
                    }
                }
            }
            
            printf("Você deseja entrar com mais alguma categoria?");
            printf("\nDigite 1 para sim ou 0 para nao: ");
            scanf("%i",&loop);
        
        }
        
        
        else{
            loop = 0;
        }
    }
    
    for(i = 0; i < n; i++){
        maior[i] = 0;
        menor[i] = 10;
        soma[i] = 0;
        for(a = 0; a < test[i]; a++){
            if(maior[i] < notas[i][a]){
                maior[i] = notas[i][a];
            }
            if(menor[i] > notas[i][a]){
                menor[i] = notas[i][a];
            }
            soma[i] = soma [i] + notas[i][a];
        }
        soma[i] = soma[i] - maior[i] - menor[i];
    }
    
    float notaf = 0;
    
    for(i = 0; i < n + t; i++){
        notaf = notaf + soma[i];
    }
    
    // A partir daqui o "é" está escrito como "eh", pois algumas vezes o acento agudo pode dar problema na línguagem C e não aparecer.
    
    for(i = 0; i < n; i++){
        printf("A nota da categoria %s eh: %.2f\n",cat[i],soma[i]);
    }
    
    printf("A nota final do candidato eh: %.2f",notaf);
    
    }
    
    else{
        printf("Não existem categorias para calcular a nota.");
    }


    return 0;
}