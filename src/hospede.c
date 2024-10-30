#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hospede.h"

#define ARQUIVO_HOSPEDES "../data/hospedes.txt"

Hospede hospedes[MAX_HOSPEDES];
int contador_hospedes = 0;

// Função para carregar dados dos hóspedes do arquivo
int carregar_hospedes() {
    FILE *file = fopen(ARQUIVO_HOSPEDES, "r");
    if (!file) {
        printf("Arquivo de hóspedes não encontrado. Será criado um novo.\n");
        return 0; // Arquivo não encontrado, mas sem erro crítico
    }

    contador_hospedes = 0;
    while (fscanf(file, "%d %99s %49s", &hospedes[contador_hospedes].id,
                  hospedes[contador_hospedes].nome,
                  hospedes[contador_hospedes].contato) == 3) {
        contador_hospedes++;
    }

    fclose(file);
    return 1; // Sucesso
}

// Função para salvar dados dos hóspedes no arquivo
int salvar_hospedes() {
    FILE *file = fopen(ARQUIVO_HOSPEDES, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo de hóspedes para salvar!\n");
        return 0; // Falha
    }

    for (int i = 0; i < contador_hospedes; i++) {
        fprintf(file, "%d %s %s\n", hospedes[i].id, hospedes[i].nome, hospedes[i].contato);
    }

    fclose(file);
    return 1; // Sucesso
}

// Função para adicionar um hóspede
int adicionar_hospede() {
    if (contador_hospedes < MAX_HOSPEDES) {
        Hospede novo_hospede;
        novo_hospede.id = contador_hospedes + 1;

        printf("Digite o nome do hóspede: ");
        scanf("%99s", novo_hospede.nome);

        printf("Digite o contato do hóspede: ");
        scanf("%49s", novo_hospede.contato);

        hospedes[contador_hospedes] = novo_hospede;
        contador_hospedes++;

        // Salva as alterações no arquivo
        if (salvar_hospedes()) {
            printf("Hóspede adicionado e salvo com sucesso!\n");
            return 1;  // Sucesso
        } else {
            printf("Falha ao salvar o hóspede no arquivo!\n");
            return 0;  // Falha ao salvar
        }
    } else {
        printf("Limite máximo de hóspedes atingido!\n");
        return 0;  // Falha
    }
}

// Função para listar hóspedes
int listar_hospedes() {
    if (contador_hospedes == 0) {
        printf("Nenhum hóspede cadastrado.\n");
        return -1;
    }

    printf("\nLista de Hóspedes:\n");
    for (int i = 0; i < contador_hospedes; i++) {
        printf("ID: %d, Nome: %s, Contato: %s\n", hospedes[i].id, hospedes[i].nome, hospedes[i].contato);
    }
    return 1; // Sucesso
}

// Função para editar um hóspede
int editar_hospede(int id) {
    for (int i = 0; i < contador_hospedes; i++) {
        if (hospedes[i].id == id) {
            printf("Digite o novo nome do hóspede: ");
            scanf("%99s", hospedes[i].nome);

            printf("Digite o novo contato do hóspede: ");
            scanf("%49s", hospedes[i].contato);

            if (salvar_hospedes()) {
                printf("Hóspede atualizado com sucesso!\n");
                return 1;
            } else {
                printf("Falha ao salvar as alterações do hóspede!\n");
                return 0;
            }
        }
    }
    printf("Hóspede com ID %d não encontrado.\n", id);
    return 0;
}

// Função para excluir um hóspede
int excluir_hospede(int id) {
    int encontrado = 0;
    for (int i = 0; i < contador_hospedes; i++) {
        if (hospedes[i].id == id) {
            encontrado = 1;
        }
        if (encontrado && i < contador_hospedes - 1) {
            hospedes[i] = hospedes[i + 1];
        }
    }
    if (encontrado) {
        contador_hospedes--;
        if (salvar_hospedes()) {
            printf("Hóspede excluído com sucesso!\n");
            return 1;
        } else {
            printf("Falha ao salvar após excluir o hóspede!\n");
            return 0;
        }
    }
    printf("Hóspede com ID %d não encontrado.\n", id);
    return 0;
}

// Função para gerenciar hóspedes
int gerenciar_hospedes() {
    int opcao;
    do {
        printf("\nGerenciamento de Hóspedes\n");
        printf("1. Adicionar Hóspede\n");
        printf("2. Listar Hóspedes\n");
        printf("3. Editar Hóspede\n");
        printf("4. Excluir Hóspede\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_hospede();
                break;
            case 2:
                listar_hospedes();
                break;
            case 3: {
                int id;
                printf("Digite o ID do hóspede a ser editado: ");
                scanf("%d", &id);
                editar_hospede(id);
                break;
            }
            case 4: {
                int id;
                printf("Digite o ID do hóspede a ser excluído: ");
                scanf("%d", &id);
                excluir_hospede(id);
                break;
            }
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 1; // Sucesso
}


