/*----------------------------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular                               *
*          Prof. Carlos Veríssimo                                             *
*-----------------------------------------------------------------------------*
* Objetivo do Programa: Criar um programa em C para armazenar e alterar dados *
*                       de produtos para uma loja, utilizando ponteiros       *
* Data - 05/11/2024                                                           * 
* Autor: Diego Lopes Sakata; Caue Ferreira; Jonathan Batista; Matheus Arthur; *
*        Diego Silva; Dennis Ramos; Pedro Yun Han                             *
*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXPRODUTOS 50

typedef struct{
    int ID;
    char nomeProduto[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

void cadastrarProduto(Produto *listaProdutos, int *contadorProduto);
void alterarProduto(Produto *listaProdutos, int ID, int contadorProduto);
void consultarProduto(Produto *listaProdutos, int ID, int contadorProduto);
void excluirProduto(Produto *listaProdutos, int ID, int *contadorProduto);
void imprimirDados(Produto *listaProdutos);
void venderProduto(Produto *listaProdutos, int ID, int quantidade, int contadorProduto);
void imprimirLista(Produto *listaProdutos, int contadorProduto);
void descontoProduto(Produto *listaProdutos, int ID, int desconto);

void cadastrarProduto(Produto *listaProdutos, int *contadorProduto){
    Produto *produto = &listaProdutos[*contadorProduto];
    produto -> ID = *contadorProduto + 1;
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", produto -> nomeProduto);
    printf("Digite a quantidade em estoque do produto (Somente numeros naturais): ");
    scanf(" %i", &produto -> quantidadeEmEstoque);
    while(produto -> quantidadeEmEstoque < 0){
        printf("A quantidade digitada esta errada. So eh possivel existir numeros positivos de produtos.\n");
        printf("Digite novamente: ");
        scanf(" %d", &produto -> quantidadeEmEstoque);
    }
    printf("Digite o valor do produto: ");
    scanf(" %lf", &produto -> valorDoProduto);
    while(produto -> valorDoProduto < 0){
        printf("O valor digitado esta errado. So eh possivel adicionar valores positivos para os produtos.\n");
        printf("Digite novamente: ");
        scanf(" %d", &produto -> quantidadeEmEstoque);
    }
    
    (*contadorProduto)++;
    printf("Produto adicionado com sucesso!\n\n");
}

void imprimirDados(Produto *listaProdutos){
    printf("\nID: %d\n", listaProdutos -> ID);
    printf("Nome: %s\n", listaProdutos -> nomeProduto);
    printf("Quantidade em estoque: %d\n", listaProdutos -> quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n\n", listaProdutos -> valorDoProduto);
}

void alterarProduto(Produto *listaProdutos, int ID, int contadorProduto){
    
    for(int i = 0; i < contadorProduto; i++){
        if(listaProdutos[i].ID == ID){
            printf("\nDados atuais do produto:\n");
            imprimirDados(&listaProdutos[i]);
    
            printf("\nDigite o nome do produto: ");
            scanf(" %[^\n]", listaProdutos[i].nomeProduto);
            printf("Digite a quantidade em estoque do produto: ");
            scanf(" %d", &listaProdutos[i].quantidadeEmEstoque);
            printf("Digite o valor do produto: ");
            scanf(" %lf", &listaProdutos[i].valorDoProduto);
            
            printf("Produto alterado com sucesso!\n\n");
            return;
        }
    }
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

void consultarProduto(Produto *listaProdutos, int ID, int contadorProduto){
    for(int i = 0; i < contadorProduto; i++){
        if(listaProdutos[i].ID == ID){
        imprimirDados(&listaProdutos[i]);
        return;
        }
    }
    
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

void excluirProduto(Produto *listaProdutos, int ID, int *contadorProduto){
    for(int i = 0; i < *contadorProduto; i++){
        if(listaProdutos[i].ID == ID){
            for(int j = i; j < *contadorProduto - 1; j++){
                strcpy(listaProdutos[j].nomeProduto, listaProdutos[j + 1].nomeProduto);
                listaProdutos[j].quantidadeEmEstoque = listaProdutos[j + 1].quantidadeEmEstoque;
                listaProdutos[j].valorDoProduto = listaProdutos[j + 1].valorDoProduto;
            }
            (*contadorProduto)--;
            printf("Produto excluido com sucesso!\n\n");
            
            return;
        }
    }
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

void venderProduto(Produto *listaProdutos, int ID, int quantidade, int contadorProduto){
    for(int i = 0; i < contadorProduto; i++){
        if(listaProdutos[i].ID == ID){
            if (listaProdutos[i].quantidadeEmEstoque >= quantidade) {
                printf("Preco da venda: %.2f\n", listaProdutos[i].valorDoProduto * quantidade);
                listaProdutos[i].quantidadeEmEstoque -= quantidade;
                printf("Produto vendido com sucesso!\n\n");
                return;
            } 
            else {
                printf("Estoque insuficiente para realizar a venda.\n\n");
            }
        }
    }
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

void imprimirLista(Produto *listaProdutos, int contadorProduto){
    printf("\n------------- Lista de todos os produtos cadastrados -------------\n\n");
    for(int i = 0; i < contadorProduto; i++){
        printf("ID: %d      Nome: %s\n", listaProdutos[i].ID, listaProdutos[i].nomeProduto);
    }
    printf("\n");
}

void descontoProduto(Produto *listaProdutos, int ID, int contadorProduto){
    for(int i = 0; i < contadorProduto; i++){
        if(listaProdutos[i].ID == ID){
            
            double desconto; 
            
            printf("\nDigite o desconto que será dado ao produto\n");
            printf("Exemplo: Se for diminuir o preco em 45/100 digite somente 45.\n");
            scanf("%lf", &desconto);
            
            listaProdutos[i].valorDoProduto = listaProdutos[i].valorDoProduto - (listaProdutos[i].valorDoProduto * (desconto / 100));
            printf("Novo valor do produto: %.2f\n", listaProdutos[i].valorDoProduto);
            printf("Desconto aplicado com sucesso!\n\n");
            return;
        }
    }
    
    printf("Produto com o ID %d não encontrado.\n\n", ID);
}

int main(){
    
    Produto listaProdutos[MAXPRODUTOS];
    int contadorProduto = 0;
    int opcao, ID, quantidade;
    
    do{
        printf("------ * MENU * ------\n");
        printf("1. Cadastrar produto\n");
        printf("2. Alterar dados do produto\n");
        printf("3. Consultar produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Consultar lista de produtos\n");
        printf("6. Vender produto\n");
        printf("7. Dar desconto a um produto\n");
        printf("8. Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);
        
        switch(opcao){
            case 1: cadastrarProduto(listaProdutos, &contadorProduto);
                    break;
            
            case 2: printf("\nDigite o ID do produto que será alterado: ");
                    scanf(" %d", &ID);
                    alterarProduto(listaProdutos, ID, contadorProduto);
                    break;
                    
            case 3: printf("\nDigite o ID do produto que deseja consultar: ");
                    scanf(" %d", &ID);
                    consultarProduto(listaProdutos, ID, contadorProduto);
                    break;
                    
            case 4: printf("\nDigite o ID do produto que deseja excluir: ");
                    scanf(" %d", &ID);
                    excluirProduto(listaProdutos, ID, &contadorProduto);
                    break;
                    
            case 5: imprimirLista(listaProdutos, contadorProduto);
                    break;
                    
            case 6: printf("\nDigite o ID do produto que deseja vender: ");
                    scanf(" %d", &ID);
                    printf("Digite a quantidade que será vendida: ");
                    scanf(" %d", &quantidade);
                    while(quantidade <= 0){
                        printf("A quantidade a ser vendida deve ser maior ou igual a 1. Entre novamente com o valor: ");
                        scanf("%d", &quantidade);
                    }
                    venderProduto(listaProdutos, ID, quantidade, contadorProduto);
                    break;
            
            case 7: printf("\nDigite o ID do produto que recebera desconto: ");
                    scanf(" %d", &ID);
                    descontoProduto(listaProdutos, ID, contadorProduto);
                    break;
            
            case 8: printf("\nObrigado por usar o nosso programa na sua loja!\n");
                    printf("Encerrando a sua execucao...");
                    break;
            
            default: printf("\nO valor digitado nao eh valido. Digite novamente: \n\n");
                     break;
        }
        
    }while(opcao != 8);
    
    return 0;
}