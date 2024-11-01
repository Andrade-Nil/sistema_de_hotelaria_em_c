#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/locacao.h"

// Definição das variáveis globais
Locacao locacoes[MAX_LOCACOES];
int contador_locacoes = 0;

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
                  locacoes[contador_locacoes].data) == 6) {
        contador_locacoes++;
        if (contador_locacoes >= MAX_LOCACOES) {
            break;
        }
    }

    fclose(file);
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
            printf("Locação adicionada com sucesso!\n");
        } else {
            printf("Erro ao abrir o arquivo para adicionar locação.\n");
        }
    } else {
        printf("Limite de locações atingido.\n");
    }
}

// Função para verificar se um quarto está disponível para uma data e número de diárias especificados
int quarto_disponivel(int id_quarto, const char* data_inicial, int diarias) {
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id_quarto == id_quarto) {
            if (datas_conflitantes(locacoes[i].data, locacoes[i].diarias, data_inicial, diarias)) {
                return 0; // Quarto indisponível
            }
        }
    }
    return 1; // Quarto disponível
}

// Função auxiliar para verificar se duas locações conflitam
int datas_conflitantes(const char* data1, int diarias1, const char* data2, int diarias2) {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);

    // Lógica para calcular conflitos entre as datas (simplificado para exemplo)
    if (ano1 == ano2 && mes1 == mes2) {
        if ((dia2 >= dia1 && dia2 < dia1 + diarias1) || (dia1 >= dia2 && dia1 < dia2 + diarias2)) {
            return 1;
        }
    }
    return 0;
}

// Função para atualizar uma locação
void atualizar_locacao(int id, Locacao locacao_atualizada) {
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id == id) {
            locacoes[i] = locacao_atualizada;
            locacoes[i].id = id; // Mantém o ID original
            salvar_locacoes();
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
            for (int j = i; j < contador_locacoes - 1; j++) {
                locacoes[j] = locacoes[j + 1];
            }
            contador_locacoes--;
            salvar_locacoes();
            printf("Locação com ID %d excluída com sucesso.\n", id);
            return;
        }
    }
    if (!found) {
        printf("Locação com ID %d não encontrada.\n", id);
    }
}

// Função para listar todas as locações
void listar_locacoes() {
    printf("\n--- Lista de Locações ---\n");
    for (int i = 0; i < contador_locacoes; i++) {
        printf("ID: %d | Hóspede: %d | Quarto: %d | Diárias: %d | Desconto: %.2f%% | Data: %s\n",
               locacoes[i].id,
               locacoes[i].id_hospede,
               locacoes[i].id_quarto,
               locacoes[i].diarias,
               locacoes[i].desconto,
               locacoes[i].data);
    }
}

// Função para salvar todas as locações no arquivo
void salvar_locacoes() {
    FILE *file = fopen("../data/locacoes.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar locações.\n");
        return;
    }

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
            case 1:
                nova_locacao.id = (contador_locacoes == 0) ? 1 : locacoes[contador_locacoes - 1].id + 1;
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

                if (quarto_disponivel(nova_locacao.id_quarto, nova_locacao.data, nova_locacao.diarias)) {
                    adicionar_locacao(nova_locacao);
                } else {
                    printf("Erro: o quarto já está ocupado na data especificada.\n");
                }
                break;

            case 2:
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

            case 3:
                printf("Digite o ID da locação que deseja excluir: ");
                scanf("%d", &id);
                excluir_locacao(id);
                break;

            case 4:
                listar_locacoes();
                break;

            case 0:
                printf("Saindo do gerenciamento de locações...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
