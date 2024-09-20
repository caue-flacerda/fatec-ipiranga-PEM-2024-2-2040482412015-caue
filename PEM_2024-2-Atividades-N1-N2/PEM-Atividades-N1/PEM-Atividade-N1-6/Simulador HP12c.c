/*--------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular *

*          Prof. Carlos Veríssimo                                    *

*--------------------------------------------------------*

* Objetivo do Programa: Criar um simulador da calculadora HP12c *

* Data - 19/09/2024                                               * 

* Autores:  Diego Lopes Sakata; Jonathan Batista Bispo; Caue Ferreira Lacerda; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han; Paulo Ricardo Ferreira Brito   *

*--------------------------------------------------------*/

// As palavras estão sem acento para não gerar nenhum erro durante a execução do código.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 4

int pilha[MAX], topo = -1;

void empilhar(int valorPilha){
    if(topo >= MAX - 1){
        printf("A pilha esta cheia. Foi digitado 5 ou mais numeros antes de um operador.\n");
        printf("O resultado estara errado.\n\n");
        return;
    }
        topo++;
        pilha[topo] = valorPilha;
}

int desempilhar(){
    if(topo < 0){
        printf("A pilha esta vazia. Mais operadores do que numeros na pilha.\n");
        printf("O resultado pode estar errado.\n\n");
        topo = 0;
        return 0;
    }
        int valor = pilha[topo];
        topo--;
        return valor;
}

void processamentoOperadores(int pilha[MAX], char operador){
    int resultado;
    int b = desempilhar();
    int a = desempilhar();
            
    switch (operador){
        case '+':   resultado = a + b; break;
        case '-':   resultado = a - b; break;
        case '*':   resultado = a * b; break;
        case '/':   if(b != 0){
                            resultado = a / b;
                    }
                    else{
                        printf("Erro: Divisao por 0"); 
                        return;
                    } break;
        default:    printf("Existe um simbolo nao compativel na expressao.\n"); 
                    printf("Entre novamente com a expressao. As operaçoes permitidas sao: + - / *\n"); 
                    printf("O resultado estara errado.\n\n");
    }
            
    empilhar(resultado);
}
    


void calculoExpressao(char expressaoRPN[100], char operador){
    char *token;
    int valorPilha, *resultado, i = 0;
    
    token = strtok(expressaoRPN, " ");
    
    while(token != NULL){
        if(isdigit(token[0])){
            valorPilha = atoi(token);
            empilhar(valorPilha);
        }
        else if(ispunct(token[0])){
            operador = token[0];
            processamentoOperadores(pilha, operador);
        }
        else {
            printf("\nErro: Caractere invalido na expressao. Por favor, insira uma expressao valida.\n");
            printf("Caracteres validos: numeros inteiros e operacoes (+ - * /)\n");
            return;
        }
        token = strtok(NULL, " ");
    }
    
    printf("O resultado da operaçao foi: %d",pilha[topo]);
}


int main()
{
    char expressaoRPN[100], operador, continuar = 's';
    int resultado = 0, i = 0;
    
    while(continuar == 's' || continuar == 'S'){
        printf("Digite a expressao que voce deseja realizar na forma RPN (5 3 + 2 *): ");
        fgets(expressaoRPN, sizeof(expressaoRPN), stdin);
        
        
        calculoExpressao(expressaoRPN, operador);
        
        printf("\n\nDeseja realizar mais uma operacao? (s/n) ");
        scanf(" %c",&continuar);
        getchar();
        
        topo = -1;
        memset(pilha, 0, sizeof(pilha));
    }
    
    printf("Obrigado por usar nossa Calculadora Fatec-HP12c");

    return 0;
}