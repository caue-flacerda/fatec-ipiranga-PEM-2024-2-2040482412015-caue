/*-----------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular              *
*          Prof. Carlos Veríssimo                            *
*------------------------------------------------------------*
* Objetivo do Programa: Criar um programa em C para loja de produtos eletrônicos *
* Data - 25/10/2024                                          * 
* Autor: Diego Lopes Sakata; Caue Ferreira; Jonathan Batista; Matheus Arthur; Diego Silva; Dennis Ramos; Pedro Yun Han   *
*---------------------------------------------------------   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Limite máximo de produtos

// Definição da struct do Produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int estoque;
} Produto;

// Funções
void inserirProduto(Produto *lista, int *contador);
void listarProdutos(Produto *lista, int contador);
void bubbleSort(Produto *lista, int contador);
void comprarProduto(Produto *lista, int contador);

// Função para inserir produtos
void inserirProduto(Produto *lista, int *contador) {
    if (*contador >= MAX) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novo;
    printf("Digite o ID do produto: ");
    scanf("%d", &novo.id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo.nome);  // Lê a linha toda
    printf("Digite a descrição: ");
    scanf(" %[^\n]", novo.descricao);
    printf("Digite o preço unitário: ");
    scanf("%f", &novo.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo.estoque);

    lista[*contador] = novo;  // Adiciona o produto à lista
    (*contador)++;  // Incrementa o contador

    printf("Produto inserido com sucesso!\n");
}

// Função Bubble Sort para ordenar produtos por nome
void bubbleSort(Produto *lista, int contador) {
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                Produto temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

// Função para listar produtos em ordem alfabética
void listarProdutos(Produto *lista, int contador) {
    if (contador == 0) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    bubbleSort(lista, contador);

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d | Nome: %s | Descrição: %s | Preço: %.2f | Estoque: %d\n",
               lista[i].id, lista[i].nome, lista[i].descricao, lista[i].preco, lista[i].estoque);
    }
}

// Função para simular a compra de um produto
void comprarProduto(Produto *lista, int contador) {
    if (contador == 0) {
        printf("Nenhum produto disponível para compra!\n");
        return;
    }

    int id, quantidade;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    // Busca o produto pelo ID
    Produto *produto = NULL;
    for (int i = 0; i < contador; i++) {
        if (lista[i].id == id) {
            produto = &lista[i];
            break;
        }
    }

    if (produto == NULL) {
        printf("Produto inexistente!\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade > produto->estoque) {
        printf("Quantidade indisponível em estoque!\n");
    } else {
        produto->estoque -= quantidade;
        printf("Compra realizada com sucesso! Estoque restante: %d\n", produto->estoque);
    }
}

int main() {
    Produto lista[MAX];  // Array de produtos
    int contador = 0;     // Contador de produtos cadastrados
    int opcao;

    do {
        printf("\n----- Loja de Eletrônicos -----\n");
        printf("1. Inserir Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(lista, &contador);
                break;
            case 2:
                listarProdutos(lista, contador);
                break;
            case 3:
                comprarProduto(lista, contador);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
