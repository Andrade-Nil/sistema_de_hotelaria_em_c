#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/locacao.h"

void test_adicionar_e_listar_locacoes() {
    FILE *file = fopen("locacoes.txt", "w");
    fclose(file);

    carregar_locacoes(); // Carrega locações, deve estar vazio
    assert(contador_locacoes == 0);

    // Adiciona nova locação
    Locacao nova_locacao = {1, 101, 201, 3, 10.0, "01/11/2024"};
    adicionar_locacao(nova_locacao);

    // Recarrega do arquivo e testa a contagem
    carregar_locacoes();
    assert(contador_locacoes == 1);
    assert(locacoes[0].id == 1);
    assert(locacoes[0].id_hospede == 101);
    assert(locacoes[0].id_quarto == 201);
    assert(strcmp(locacoes[0].data, "01/11/2024") == 0);

    // Teste de atualização
    Locacao locacao_atualizada = {1, 102, 202, 4, 5.0, "02/11/2024"};
    atualizar_locacao(1, locacao_atualizada);
    carregar_locacoes();
    assert(locacoes[0].id_hospede == 102);
    assert(strcmp(locacoes[0].data, "02/11/2024") == 0);

    // Teste de exclusão
    excluir_locacao(1);
    carregar_locacoes();
    assert(contador_locacoes == 0); // Verifica se a locação foi excluída

    printf("Teste de adicionar, atualizar e excluir locações passou.\n");
}

int main() {
    test_adicionar_e_listar_locacoes();
    printf("Todos os testes de locação passaram.\n");
    return 0;
}
