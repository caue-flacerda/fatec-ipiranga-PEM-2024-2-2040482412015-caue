/*--------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular *

*          Prof. Carlos Veríssimo                                    *

*--------------------------------------------------------*

* Objetivo do Programa: Correção de todas as inconsistências que existem, segundo o desafio de PEM   *

* Data - 21/09/2024                                               * 

* Autores:  Diego Lopes Sakata; Jonathan Batista Bispo; Caue Ferreira Lacerda; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han;   *

*--------------------------------------------------------*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PILHA 4

void exibirPilha(int pilha[]) {
    printf("Pilha: [T: %d] [Z: %d] [Y: %d] [X: %d]\n", pilha[3], pilha[2], pilha[1], pilha[0]);
}

void empurrar(int pilha[], int valor) {
    if (pilha[TAMANHO_PILHA - 1] != 0) {
        printf("Erro: Pilha cheia, não é possível empurrar mais elementos.\n");
        return;
    }
    for (int i = TAMANHO_PILHA - 1; i > 0; i--) {
        pilha[i] = pilha[i - 1];
    }
    pilha[0] = valor;
}

void executarOperacao(int pilha[], char operador) {
    if (pilha[0] == 0 && pilha[1] == 0) {
        printf("Erro: Pilha vazia, não é possível executar operações.\n");
        return;
    }
    
    int resultado;

    if (operador == '+') {
        resultado = pilha[1] + pilha[0];
    } else if (operador == '-') {
        resultado = pilha[1] - pilha[0];
    } else if (operador == '*') {
        resultado = pilha[1] * pilha[0];
    } else if (operador == '/') {
        if (pilha[0] == 0) {
            printf("Erro: Divisao por zero nao permitida.\n");
            return;
        }
        resultado = pilha[1] / pilha[0];
    } else {
        printf("Operador invalido!\n");
        return;
    }

    pilha[0] = resultado; 
    for (int i = 1; i < TAMANHO_PILHA; i++) {
        pilha[i] = pilha[i + 1];
    }
    pilha[TAMANHO_PILHA - 1] = 0; 
}

int main() {
    int pilha[TAMANHO_PILHA] = {0, 0, 0, 0};
    char entrada[100];
    char continuar;
    printf("Bem-vindo a Calculadora Fatec-HP12c!\n");
    
    do {
        printf("\nDigite a expressao em formato RPN (ex: 5 1 2 + 4 * + 3) ou 'sair' para encerrar: ");
        fgets(entrada, sizeof(entrada), stdin);

        if (strncmp(entrada, "sair", 4) == 0 || strncmp(entrada, "SAIR", 4) == 0){
            break;
        }

        char* token = strtok(entrada, " ");
        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                int valor = atoi(token);
                empurrar(pilha, valor);
                exibirPilha(pilha);
            }
            else {
                executarOperacao(pilha, token[0]);
                exibirPilha(pilha);
            }
            token = strtok(NULL, " \n");
        }
        printf("\nResultado final: %d\n", pilha[0]);
        printf("\nDeseja realizar outra operacao? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); 
    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");
    return 0;
}