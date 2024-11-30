/*----------------------------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular                               *
*          Prof. Carlos Veríssimo                                             *
*-----------------------------------------------------------------------------*
* Objetivo do Programa: Refatorando o Código                                  *
* Data - 29/11/2024                                                           * 
* Autor: Cauê Ferreira Lacerda                                                *
*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 100
#define NOME_MAX 50
#define DESCRICAO_MAX 100

typedef struct {
    int id;
    char nome[NOME_MAX];
    char descricao[DESCRICAO_MAX];
    double precoUnitario; // Corrigido para double (antes era float)
    int qteDispo;
} Produto;

// Funções auxiliares para ler entradas com validação
int lerInteiroPositivo() {
    int num;
    char ch;

    while (1) {
        if (scanf("%d", &num) != 1) {
            while ((ch = getchar()) != '\n' && ch != EOF); // Limpa o buffer até o final da linha
            printf("Entrada inválida! Digite um número inteiro positivo: ");
        } else {
            // Verifica se há mais caracteres após o número (como espaços ou outros números)
            if ((ch = getchar()) != '\n') {
                while (ch != '\n' && ch != EOF) {
                    ch = getchar(); // Limpa o restante da linha
                }
                printf("Entrada inválida! Digite apenas um número inteiro positivo: ");
            } else if (num <= 0) {
                printf("Entrada inválida! Digite um número inteiro positivo: ");
            } else {
                return num;
            }
        }
    }
}

double lerDoublePositivo() {
    double num;
    while (scanf("%lf", &num) != 1 || num <= 0) {
        while (getchar() != '\n'); // Limpa o buffer
        printf("Entrada inválida! Digite um número positivo válido: ");
    }
    return num;
}

// Função de leitura de string segura (sem números)
void lerStringSegura(char *destino, int tamanho, const char *mensagem) {
    int valido;
    do {
        printf("%s: ", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0'; // Remove o '\n' da string
        
        valido = 1;
        for (int i = 0; destino[i] != '\0'; i++) {
            if (isdigit(destino[i])) {
                valido = 0; 
                printf("Erro! O nome não pode conter numero. Tente novamente.\n");
                break;
            }
        }
    } while (!valido);
}

void inserirProduto(Produto *produtos, int *cont);
void consultarProduto(Produto *produtos, int cont);
void alterarProduto(Produto *produtos, int cont);
void excluirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void comprarProduto(Produto *produtos, int cont);
void imprimirProduto(Produto *produto);
int produtoExiste(Produto *produtos, int cont, int id);
void aplicarDesconto(Produto *produtos, int cont);

int main() {
    Produto produtos[MAX_PRODUTOS]; // Array para armazenar até 100 produtos
    int cont = 0; // Contador de produtos
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Consultar produto\n");
        printf("4. Alterar produto\n");
        printf("5. Excluir produto\n");
        printf("6. Aplicar desconto\n");
        printf("7. Comprar produto\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        opcao = lerInteiroPositivo();  // Usando a função de leitura com validação

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                consultarProduto(produtos, cont);
                break;
            case 4:
                alterarProduto(produtos, cont);
                break;
            case 5:
                excluirProduto(produtos, &cont);
                break;
            case 6:
                aplicarDesconto(produtos, cont);
                break;
            case 7:
                comprarProduto(produtos, cont);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont < MAX_PRODUTOS) { // Verifica se há espaço no array
        Produto novoProduto;
        int idProduto;

        printf("Informe o ID do produto: ");
        idProduto = lerInteiroPositivo();

        if (produtoExiste(produtos, *cont, idProduto)) {
            printf("Erro: Produto com esse ID já existe.\n");
            return;
        }

        novoProduto.id = idProduto;
        lerStringSegura(novoProduto.nome, NOME_MAX, "Nome do produto");

        lerStringSegura(novoProduto.descricao, DESCRICAO_MAX, "Descricao do produto");

        printf("Informe o preco unitario: ");
        novoProduto.precoUnitario = lerDoublePositivo();

        printf("Informe a quantidade disponivel: ");
        novoProduto.qteDispo = lerInteiroPositivo();

        produtos[*cont] = novoProduto; // Adiciona o novo produto ao array
        (*cont)++; // Incrementa o contador
        printf("Produto inserido com sucesso!\n");
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

int produtoExiste(Produto *produtos, int cont, int id) {
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == id) {
            return 1; // Produto já existe
        }
    }
    return 0; // Produto não encontrado
}

void listarProdutos(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < cont; i++) {
        imprimirProduto(&produtos[i]);
    }
}

void imprimirProduto(Produto *produto) {
    printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2lf, Estoque: %d\n", 
        produto->id, produto->nome, produto->descricao, produto->precoUnitario, produto->qteDispo);
}

void consultarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja consultar: ");
    idProduto = lerInteiroPositivo();

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void alterarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja alterar: ");
    idProduto = lerInteiroPositivo();

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            lerStringSegura(produtos[i].nome, NOME_MAX, "Novo nome");

            
            lerStringSegura(produtos[i].descricao, DESCRICAO_MAX, "Nova descricao");

            printf("Novo preco unitario: ");
            produtos[i].precoUnitario = lerDoublePositivo();
            printf("Nova quantidade disponivel: ");
            produtos[i].qteDispo = lerInteiroPositivo();
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void excluirProduto(Produto *produtos, int *cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja excluir: ");
    idProduto = lerInteiroPositivo();

    for (int i = 0; i < *cont; i++) {
        if (produtos[i].id == idProduto) {
            for (int j = i; j < *cont - 1; j++) {
                produtos[j] = produtos[j + 1]; // Move os produtos para preencher o espaço
            }
            (*cont)--; // Decrementa o contador
            printf("Produto excluido com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void comprarProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado para compra.\n");
        return;
    }

    int idProduto, quantidade;
    printf("Informe o ID do produto que deseja comprar: ");
    idProduto = lerInteiroPositivo();

    // Busca o produto pelo ID
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Informe a quantidade que deseja comprar: ");
            quantidade = lerInteiroPositivo();

            if (quantidade > produtos[i].qteDispo) {
                printf("Estoque insuficiente. Apenas %d disponiveis.\n", produtos[i].qteDispo);
            } else {
                produtos[i].qteDispo -= quantidade; // Atualiza a quantidade disponível
                printf("Compra realizada com sucesso! Total: %.2lf\n", produtos[i].precoUnitario * quantidade);
            }
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void aplicarDesconto(Produto *produtos, int cont) {
    int idProduto;
    double desconto;

    printf("Informe o ID do produto para aplicar o desconto: ");
    idProduto = lerInteiroPositivo();

    // Busca o produto pelo ID
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Informe o percentual de desconto (0-100): ");
            desconto = lerDoublePositivo();

            if (desconto < 0 || desconto > 100) {
                printf("Desconto inválido! Deve estar entre 0 e 100.\n");
                return;
            }

            produtos[i].precoUnitario *= (1 - desconto / 100); // Aplica o desconto
            printf("Desconto aplicado com sucesso! Novo preco: %.2lf\n", produtos[i].precoUnitario);
            return;
        }
    }
    printf("Produto inexistente.\n");
}
