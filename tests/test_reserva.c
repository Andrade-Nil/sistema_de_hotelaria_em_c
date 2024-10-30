#include <assert.h>
#include <stdio.h>
#include "../include/reserva.h"

void test_adicionar_reserva_antecipada() {
    Reserva nova_reserva = {1, 101, 201, "01/11/2024", "05/11/2024"};
    adicionar_reserva_antecipada(nova_reserva);
    assert(get_contador_reservas() == 1);
}

void test_listar_reservas_antecipadas() {
    listar_reservas_antecipadas();
}

void test_editar_reserva() {
    Reserva reserva_editada = {1, 101, 201, "02/11/2024", "06/11/2024"};
    assert(editar_reserva(1, reserva_editada) == 1);
}

void test_excluir_reserva() {
    assert(excluir_reserva(1) == 1);
    assert(get_contador_reservas() == 0);
}

int main() {
    carregar_reservas_do_arquivo();
    test_adicionar_reserva_antecipada();
    test_listar_reservas_antecipadas();
    test_editar_reserva();
    test_excluir_reserva();
    printf("Todos os testes para 'Reserva' passaram.\n");
    return 0;
}
