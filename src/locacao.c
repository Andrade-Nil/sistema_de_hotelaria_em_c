#include <stdio.h>
#include <stdlib.h>
#include "../include/locacao.h"

Locacao locacoes[MAX_LOCACOES]; // Definição da variável global
int contador_locacoes = 0; // Definição da variável global

// Função para carregar locações do arquivo
void carregar_locacoes() {
    FILE *file = fopen("../data/locacoes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de locações.\n");
        return;
    }

    contador_locacoes = 0; // Reseta o contador
    while (fscanf(file, "%d,%d,%d,%d,%f,%10s",
                  &locacoes[contador_locacoes].id,
                  &locacoes[contador_locacoes].id_hospede,
                  &locacoes[contador_locacoes].id_quarto,
                  &locacoes[contador_locacoes].diarias,
                  &locacoes[contador_locacoes].desconto,
                  locacoes[contador_locacoes].data) == 6) { // Checar se todas as 6 entradas foram lidas
        contador_locacoes++;
        if (contador_locacoes >= MAX_LOCACOES) { // Limitar o número de locações
            break;
        }
    }

    fclose(file);
}

// Função para gerenciar locações
void gerenciar_locacoes() {
    int opcao;
    Locacao nova_locacao;
    int id;

    carregar_locacoes(); // Carrega as locações do arquivo ao iniciar o gerenciamento

    do {
        printf("\n--- Gerenciamento de Locações ---\n");
        printf("1. Adicionar Locações\n");
        printf("2. Atualizar Locações\n");
        printf("3. Excluir Locações\n");
        printf("4. Listar Locações\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Adicionar locação
                printf("Digite o ID da nova locação: ");
                scanf("%d", &nova_locacao.id);
                printf("Digite o ID do hóspede: ");
                scanf("%d", &nova_locacao.id_hospede);
                printf("Digite o ID do quarto: ");
                scanf("%d", &nova_locacao.id_quarto);
                printf("Digite o número de diárias: ");
                scanf("%d", &nova_locacao.diarias);
                printf("Digite o desconto: ");
                scanf("%f", &nova_locacao.desconto);
                printf("Digite a data (dd/mm/aaaa): ");
                scanf("%s", nova_locacao.data);
                adicionar_locacao(nova_locacao);
                break;

            case 2: // Atualizar locação
                printf("Digite o ID da locação que deseja atualizar: ");
                scanf("%d", &id);
                printf("Digite o novo ID do hóspede: ");
                scanf("%d", &nova_locacao.id_hospede);
                printf("Digite o novo ID do quarto: ");
                scanf("%d", &nova_locacao.id_quarto);
                printf("Digite o novo número de diárias: ");
                scanf("%d", &nova_locacao.diarias);
                printf("Digite o novo desconto: ");
                scanf("%f", &nova_locacao.desconto);
                printf("Digite a nova data (dd/mm/aaaa): ");
                scanf("%s", nova_locacao.data);
                atualizar_locacao(id, nova_locacao);
                break;

            case 3: // Excluir locação
                printf("Digite o ID da locação que deseja excluir: ");
                scanf("%d", &id);
                excluir_locacao(id);
                break;

            case 4: // Listar locações
                listar_locacoes();
                break;

            case 0: // Sair
                printf("Saindo do gerenciamento de locações...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Função para adicionar uma locação e salvar no arquivo
void adicionar_locacao(Locacao nova_locacao) {
    if (contador_locacoes < MAX_LOCACOES) {
        locacoes[contador_locacoes++] = nova_locacao;

        FILE *file = fopen("../data/locacoes.txt", "a");
        if (file != NULL) {
            fprintf(file, "%d,%d,%d,%d,%.2f,%s\n",
                    nova_locacao.id,
                    nova_locacao.id_hospede,
                    nova_locacao.id_quarto,
                    nova_locacao.diarias,
                    nova_locacao.desconto,
                    nova_locacao.data);
            fclose(file);
        } else {
            printf("Erro ao abrir o arquivo para adicionar locação.\n");
        }
    } else {
        printf("Limite de locações atingido.\n");
    }
}

// Função para atualizar uma locação
void atualizar_locacao(int id, Locacao locacao_atualizada) {
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id == id) {
            locacoes[i] = locacao_atualizada;
            salvar_locacoes(); // Salva todas as locações no arquivo
            printf("Locação com ID %d atualizada com sucesso.\n", id);
            return;
        }
    }
    printf("Locação com ID %d não encontrada.\n", id);
}

// Função para excluir uma locação
void excluir_locacao(int id) {
    int found = 0;
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id == id) {
            found = 1;
            // Move as locações para preencher o espaço deixado
            for (int j = i; j < contador_locacoes - 1; j++) {
                locacoes[j] = locacoes[j + 1];
            }
            contador_locacoes--;
            printf("Locação com ID %d excluída com sucesso.\n", id);
            break;
        }
    }

    if (found) {
        salvar_locacoes(); // Salva todas as locações no arquivo
    } else {
        printf("Locação com ID %d não encontrada.\n", id);
    }
}

// Função auxiliar para salvar todas as locações no arquivo
void salvar_locacoes() {
    FILE *file = fopen("../data/locacoes.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < contador_locacoes; i++) {
            fprintf(file, "%d,%d,%d,%d,%.2f,%s\n",
                    locacoes[i].id,
                    locacoes[i].id_hospede,
                    locacoes[i].id_quarto,
                    locacoes[i].diarias,
                    locacoes[i].desconto,
                    locacoes[i].data);
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo para salvar locações.\n");
    }
}

// Função para listar todas as locações
void listar_locacoes() {
    if (contador_locacoes == 0) {
        printf("Nenhuma locação cadastrada.\n");
        return;
    }

    printf("\nLista de Locações:\n");
    for (int i = 0; i < contador_locacoes; i++) {
        printf("ID: %d, ID Hóspede: %d, ID Quarto: %d, Diárias: %d, Desconto: %.2f, Data: %s\n",
               locacoes[i].id,
               locacoes[i].id_hospede,
               locacoes[i].id_quarto,
               locacoes[i].diarias,
               locacoes[i].desconto,
               locacoes[i].data);
    }
}
