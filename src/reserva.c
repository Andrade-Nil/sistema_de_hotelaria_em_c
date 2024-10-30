#include <stdio.h>
#include <string.h>
#include "../include/reserva.h"

Reserva reservas[MAX_RESERVAS]; // Array de reservas
int contador_reservas = 0;      // Contador de reservas cadastradas

// Função para salvar reservas no arquivo
void salvar_reservas_no_arquivo() {
    FILE *file = fopen("../data/reservas.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de reservas!\n");
        return;
    }
    for (int i = 0; i < contador_reservas; i++) {
        fprintf(file, "%d,%d,%d,%s,%s\n",
                reservas[i].id,
                reservas[i].id_hospede,
                reservas[i].id_quarto,
                reservas[i].data_entrada,
                reservas[i].data_saida);
    }
    fclose(file);
}

// Função para carregar reservas do arquivo
void carregar_reservas_do_arquivo() {
    FILE *file = fopen("../data/reservas.txt", "r");
    if (file == NULL) {
        printf("Nenhum arquivo de reservas encontrado. Iniciando com lista vazia.\n");
        return;
    }
    contador_reservas = 0;
    while (fscanf(file, "%d,%d,%d,%10[^,],%10[^\n]\n",
                  &reservas[contador_reservas].id,
                  &reservas[contador_reservas].id_hospede,
                  &reservas[contador_reservas].id_quarto,
                  reservas[contador_reservas].data_entrada,
                  reservas[contador_reservas].data_saida) == 5) {
        contador_reservas++;
    }
    fclose(file);
}

// Função para adicionar uma reserva antecipada
void adicionar_reserva_antecipada(Reserva nova_reserva) {
    if (contador_reservas < MAX_RESERVAS) {
        reservas[contador_reservas] = nova_reserva;
        contador_reservas++;
        salvar_reservas_no_arquivo();
        printf("Reserva antecipada adicionada com sucesso!\n");
    } else {
        printf("Limite máximo de reservas atingido!\n");
    }
}

// Função para listar reservas antecipadas
void listar_reservas_antecipadas() {
    if (contador_reservas == 0) {
        printf("Nenhuma reserva antecipada cadastrada.\n");
        return;
    }

    printf("Lista de Reservas Antecipadas:\n");
    for (int i = 0; i < contador_reservas; i++) {
        printf("ID: %d, Hóspede ID: %d, Quarto ID: %d, Entrada: %s, Saída: %s\n",
               reservas[i].id, reservas[i].id_hospede, reservas[i].id_quarto,
               reservas[i].data_entrada, reservas[i].data_saida);
    }
}

// Função para editar uma reserva
int editar_reserva(int id, Reserva reserva_editada) {
    for (int i = 0; i < contador_reservas; i++) {
        if (reservas[i].id == id) {
            reservas[i] = reserva_editada;
            salvar_reservas_no_arquivo();
            printf("Reserva editada com sucesso!\n");
            return 1; // Sucesso
        }
    }
    printf("Reserva com ID %d não encontrada.\n", id);
    return 0; // Falha
}

// Função para excluir uma reserva
int excluir_reserva(int id) {
    int encontrado = 0;
    for (int i = 0; i < contador_reservas; i++) {
        if (reservas[i].id == id) {
            encontrado = 1;
        }
        if (encontrado && i < contador_reservas - 1) {
            reservas[i] = reservas[i + 1];
        }
    }
    if (encontrado) {
        contador_reservas--;
        salvar_reservas_no_arquivo();
        printf("Reserva excluída com sucesso!\n");
        return 1; // Sucesso
    }
    printf("Reserva com ID %d não encontrada.\n", id);
    return 0; // Falha
}

// Função para acessar o contador de reservas
int get_contador_reservas() {
    return contador_reservas;
}

// Menu para adicionar uma nova reserva
void menu_adicionar_reserva() {
    Reserva nova_reserva;
    printf("Digite o ID da reserva: ");
    scanf("%d", &nova_reserva.id);
    printf("Digite o ID do hóspede: ");
    scanf("%d", &nova_reserva.id_hospede);
    printf("Digite o ID do quarto: ");
    scanf("%d", &nova_reserva.id_quarto);
    printf("Digite a data de entrada (DD/MM/YYYY): ");
    scanf("%s", nova_reserva.data_entrada);
    printf("Digite a data de saída (DD/MM/YYYY): ");
    scanf("%s", nova_reserva.data_saida);

    adicionar_reserva_antecipada(nova_reserva);
}
