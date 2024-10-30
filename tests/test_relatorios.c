#include <stdio.h>
#include "../include/relatorios.h"
#include "../include/locacao.h"

// Exemplo de teste para relatório de locações por hóspede
void test_relatorio_locacoes_por_hospede() {
    printf("Teste: Relatório de Locações por Hóspede\n");
    relatorio_locacoes_por_hospede(101); // Testa com um hóspede específico
}

// Exemplo de teste para relatório de locações por quarto
void test_relatorio_locacoes_por_quarto() {
    printf("Teste: Relatório de Locações por Quarto\n");
    relatorio_locacoes_por_quarto(201); // Testa com um quarto específico
}

// Exemplo de teste para relatório de locações por data
void test_relatorio_locacoes_por_data() {
    printf("Teste: Relatório de Locações por Data\n");
    relatorio_locacoes_por_data("01/10/2024"); // Testa com uma data específica
}

int main() {
    carregar_locacoes(); // Carrega locações do arquivo antes de testar
    test_relatorio_locacoes_por_hospede();
    test_relatorio_locacoes_por_quarto();
    test_relatorio_locacoes_por_data();
    printf("Testes de relatórios concluídos.\n");
    return 0;
}
