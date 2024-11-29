#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;

void adicionarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    novoProduto.id = totalProdutos + 1;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);

    printf("Digite a quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &novoProduto.preco);

    estoque[totalProdutos] = novoProduto;
    totalProdutos++;

    printf("Produto adicionado com sucesso!\n");
}

void exibirMenu() {
    printf("\n=== Sistema de Gerenciamento de Estoque ===\n");
    printf("1. Adicionar produto\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao inválida! Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}
