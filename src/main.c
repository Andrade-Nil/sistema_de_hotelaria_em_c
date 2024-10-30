#include <stdio.h>
#include "../include/quarto.h"
#include "../include/hospede.h"
#include "../include/locacao.h"
#include "../include/relatorios.h"
#include "../include/alertas.h"
#include "../include/reserva.h"
#include "../include/util.h"

void exibir_menu() {
    printf("\nHotel System - Menu Principal\n");
    printf("1. Gerenciar Quartos\n");
    printf("2. Gerenciar Hóspedes\n");
    printf("3. Gerenciar Locações\n");
    printf("4. Relatórios\n");
    printf("5. Alertas\n");
    printf("6. Reservas Antecipadas\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    verificar_arquivos();  // Verifica e cria os arquivos de dados se necessário

    int opcao;
    
    do {
        exibir_menu();
        
        // Validação de entrada
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            // Limpa o buffer
            while (getchar() != '\n');
            opcao = -1; // Para manter o loop
            continue;
        }
        
        switch (opcao) {
            case 1:
                gerenciar_quartos();
                break;
            case 2:
                gerenciar_hospedes();
                break;
            case 3:
                gerenciar_locacoes();
                break;
            case 4:
                listar_locacoes();
                break;
            case 5:
                // Funções de alertas
                break;
            case 6:
                menu_adicionar_reserva(); // Altera aqui para chamar menu_adicionar_reserva()
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    
    return 0;
}
