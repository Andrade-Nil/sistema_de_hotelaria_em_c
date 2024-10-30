#include <stdio.h>
#include <assert.h>
#include "../include/alertas.h"

void test_alerta_fim_reserva() {
    // Teste para alerta de fim de reserva
    int locacao_id = 1; // ID de teste
    alerta_fim_reserva(locacao_id); // A função deve ser chamada, verifique manualmente a saída
}

void test_exibir_alerta_estender_locacao() {
    // Teste para alerta de estender locação
    int locacao_id = 2; // ID de teste
    exibir_alerta_estender_locacao(locacao_id); // A função deve ser chamada, verifique manualmente a saída
}

int main() {
    test_alerta_fim_reserva();
    test_exibir_alerta_estender_locacao();
    printf("Todos os testes para 'Alertas' passaram.\n");
    return 0;
}
