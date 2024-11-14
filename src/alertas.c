#include <stdio.h>
#include <time.h>
#include "../include/alertas.h"
#include "../include/util.h"
#include "../include/reserva.h"

extern Reserva reservas[];
extern int contador_reservas;

void alerta_fim_reserva(int id_reserva) {
    time_t now;
    time(&now);
    struct tm *data_atual = localtime(&now);
    char data_atual_str[11];
    strftime(data_atual_str, sizeof(data_atual_str), "%d/%m/%Y", data_atual);
    
    for (int i = 0; i < contador_reservas; i++) {
        if (reservas[i].id == id_reserva) {
            int dias_restantes = diferenca_dias(data_atual_str, reservas[i].data_saida);
            if (dias_restantes <= 2) {
                printf("⚠️ Alerta: A reserva ID %d está próxima do fim. Dias restantes: %d\n", id_reserva, dias_restantes);
            }
            return;
        }
    }
    printf("Reserva ID %d não encontrada.\n", id_reserva);
}

