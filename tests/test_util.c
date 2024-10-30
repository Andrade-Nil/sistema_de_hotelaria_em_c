#include <assert.h>
#include <stdio.h>
#include "../include/util.h"

void test_validar_data() {
    int resultado = validar_data("2024-10-01");
    assert(resultado == 1); // Espera que a função retorne 1 (data válida)

    resultado = validar_data("2024-02-30");
    assert(resultado == 0); // Data inválida
}

int main() {
    test_validar_data();
    printf("Todos os testes para 'Util' passaram.\n");
    return 0;
}
