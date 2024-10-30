#include <assert.h>
#include <stdio.h>
#include "../include/hospede.h"

void test_adicionar_hospede() {
    int inicial = contador_hospedes;
    int resultado = adicionar_hospede();
    assert(resultado == 1); // Espera que a função retorne 1 (sucesso)
    assert(contador_hospedes == inicial + 1); // Confirma que o contador aumentou
}


int main() {
    // Carrega dados dos hóspedes do arquivo ao iniciar o programa
    carregar_hospedes();
    // Você pode usar um loop para fazer testes repetidos ou chamar várias funções de teste
    test_adicionar_hospede();
    printf("Todos os testes para 'Hospede' passaram.\n");
    return 0;
}
