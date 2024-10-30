#include <assert.h>
#include "../include/quarto.h"

void test_adicionar_quarto() {
    // Testando a adição de um quarto
    int resultado = adicionar_quarto("Suíte Luxo", 200.00);
    assert(resultado == 1);  // Espera que a função retorne 1 (sucesso)
    assert(contador_quartos == 1);  // Deve haver um quarto cadastrado
}

int main() {
    test_adicionar_quarto();
    printf("Todos os testes para 'Quarto' passaram.\n");
    return 0;
}
