#include <stdio.h>
#include <string.h>
#include "../include/quarto.h"
#include "../include/hospede.h"
#include "../include/locacao.h"
#include "../include/relatorios.h"
#include "../include/alertas.h"
#include "../include/reserva.h"
#include "../include/util.h"
// #include "../src/locacao.c"

// Relatório de locações por hóspede
void relatorio_locacoes_por_hospede(int id_hospede) {
    printf("Relatório de locações para o hóspede ID %d:\n", id_hospede);
    int encontrado = 0;
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id_hospede == id_hospede) {
            printf("ID Locação: %d, Quarto ID: %d, Diárias: %d, Desconto: %.2f, Data: %s\n",
                   locacoes[i].id, locacoes[i].id_quarto, locacoes[i].diarias,
                   locacoes[i].desconto, locacoes[i].data);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma locação encontrada para o hóspede ID %d.\n", id_hospede);
    }
}

// Relatório de locações por quarto
void relatorio_locacoes_por_quarto(int id_quarto) {
    printf("Relatório de locações para o quarto ID %d:\n", id_quarto);
    int encontrado = 0;
    for (int i = 0; i < contador_locacoes; i++) {
        if (locacoes[i].id_quarto == id_quarto) {
            printf("ID Locação: %d, Hóspede ID: %d, Diárias: %d, Desconto: %.2f, Data: %s\n",
                   locacoes[i].id, locacoes[i].id_hospede, locacoes[i].diarias,
                   locacoes[i].desconto, locacoes[i].data);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma locação encontrada para o quarto ID %d.\n", id_quarto);
    }
}

// Relatório de locações por data
void relatorio_locacoes_por_data(const char* data) {
    printf("Relatório de locações na data %s:\n", data);
    int encontrado = 0;
    for (int i = 0; i < contador_locacoes; i++) {
        if (strcmp(locacoes[i].data, data) == 0) {
            printf("ID Locação: %d, Hóspede ID: %d, Quarto ID: %d, Diárias: %d, Desconto: %.2f\n",
                   locacoes[i].id, locacoes[i].id_hospede, locacoes[i].id_quarto,
                   locacoes[i].diarias, locacoes[i].desconto);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma locação encontrada na data %s.\n", data);
    }
}
