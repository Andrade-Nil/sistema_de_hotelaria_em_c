#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/quarto.h"

#define ARQUIVO_QUARTOS "../data/quartos.txt"

Quarto quartos[MAX_QUARTOS];
int contador_quartos = 0;

// Função para carregar dados dos quartos do arquivo
int carregar_quartos() {
    FILE *file = fopen(ARQUIVO_QUARTOS, "r");
    if (!file) {
        printf("Arquivo de quartos não encontrado. Será criado um novo ao salvar.\n");
        return 0;
    }

    contador_quartos = 0;
    while (fscanf(file, "%d,%49[^,],%f\n", &quartos[contador_quartos].id,
                  quartos[contador_quartos].tipo, &quartos[contador_quartos].valor_diaria) == 3) {
        contador_quartos++;
    }

    fclose(file);
    return 1;
}

// Função para salvar dados dos quartos no arquivo
int salvar_quartos() {
    FILE *file = fopen(ARQUIVO_QUARTOS, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return 0;
    }

    for (int i = 0; i < contador_quartos; i++) {
        fprintf(file, "%d,%s,%.2f\n", quartos[i].id, quartos[i].tipo, quartos[i].valor_diaria);
    }

    fclose(file);
    return 1;
}

// Função para adicionar um quarto
int adicionar_quarto(const char *tipo, float valor_diaria) {
    if (contador_quartos < MAX_QUARTOS) {
        Quarto novo_quarto;
        novo_quarto.id = contador_quartos + 1;
        strncpy(novo_quarto.tipo, tipo, sizeof(novo_quarto.tipo) - 1);
        novo_quarto.tipo[sizeof(novo_quarto.tipo) - 1] = '\0';
        novo_quarto.valor_diaria = valor_diaria;

        quartos[contador_quartos++] = novo_quarto;
        printf("Quarto adicionado com sucesso!\n");

        salvar_quartos();  // Salva automaticamente após adicionar
        return 1;
    } else {
        printf("Limite máximo de quartos atingido!\n");
        return 0;
    }
}

// Função para listar quartos
int listar_quartos() {
    if (contador_quartos == 0) {
        printf("Nenhum quarto cadastrado.\n");
        return -1;
    }

    printf("\nLista de Quartos:\n");
    for (int i = 0; i < contador_quartos; i++) {
        printf("ID: %d, Tipo: %s, Valor Diária: %.2f\n", quartos[i].id, quartos[i].tipo, quartos[i].valor_diaria);
    }

    return contador_quartos;
}

// Função para atualizar um quarto
int atualizar_quarto(int id, const char *novo_tipo, float novo_valor_diaria) {
    for (int i = 0; i < contador_quartos; i++) {
        if (quartos[i].id == id) {
            strncpy(quartos[i].tipo, novo_tipo, sizeof(quartos[i].tipo) - 1);
            quartos[i].tipo[sizeof(quartos[i].tipo) - 1] = '\0';
            quartos[i].valor_diaria = novo_valor_diaria;
            salvar_quartos();
            printf("Quarto atualizado com sucesso.\n");
            return 1;
        }
    }
    printf("Quarto com ID %d não encontrado.\n", id);
    return 0;
}

// Função para excluir um quarto
int excluir_quarto(int id) {
    int encontrado = 0;
    for (int i = 0; i < contador_quartos; i++) {
        if (quartos[i].id == id) {
            encontrado = 1;
        }
        if (encontrado && i < contador_quartos - 1) {
            quartos[i] = quartos[i + 1];
        }
    }
    if (encontrado) {
        contador_quartos--;
        salvar_quartos();
        printf("Quarto excluído com sucesso.\n");
        return 1;
    }
    printf("Quarto com ID %d não encontrado.\n", id);
    return 0;
}

// Função para gerenciar os quartos
void gerenciar_quartos() {
    // Carrega os dados dos quartos ao iniciar a função de gerenciamento
    carregar_quartos();

    int opcao;
    do {
        printf("\nGerenciamento de Quartos\n");
        printf("1. Adicionar Quarto\n");
        printf("2. Listar Quartos\n");
        printf("3. Atualizar Quarto\n");
        printf("4. Excluir Quarto\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                char tipo[50];
                float valor_diaria;

                printf("Digite o tipo do quarto: ");
                scanf("%s", tipo);
                printf("Digite o valor da diária: ");
                scanf("%f", &valor_diaria);
                
                adicionar_quarto(tipo, valor_diaria);
                break;
            }
            case 2:
                listar_quartos();
                break;
            case 3: {
                int id;
                char novo_tipo[50];
                float novo_valor_diaria;

                printf("Digite o ID do quarto a ser atualizado: ");
                scanf("%d", &id);
                printf("Digite o novo tipo do quarto: ");
                scanf("%s", novo_tipo);
                printf("Digite o novo valor da diária: ");
                scanf("%f", &novo_valor_diaria);
                
                atualizar_quarto(id, novo_tipo, novo_valor_diaria);
                break;
            }
            case 4: {
                int id;
                printf("Digite o ID do quarto a ser excluído: ");
                scanf("%d", &id);
                excluir_quarto(id);
                break;
            }
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
