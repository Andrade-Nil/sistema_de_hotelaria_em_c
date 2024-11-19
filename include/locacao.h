#ifndef LOCACAO_H
#define LOCACAO_H

#define MAX_LOCACOES 100 // Defina o máximo de locações

typedef struct {
    int id;
    int id_hospede;
    int id_quarto;
    int diarias;
    float desconto;
    char data[11]; // dd/mm/yyyy
} Locacao;

// Declare as funções
void carregar_locacoes();
void adicionar_locacao(Locacao nova_locacao);
void atualizar_locacao(int id, Locacao locacao_atualizada);
void excluir_locacao(int id);
void salvar_locacoes();
void listar_locacoes();
void gerenciar_locacoes();

// Função para verificar se o quarto está disponível
int quarto_disponivel(int id_quarto, const char* data_inicial, int diarias);
int datas_conflitantes(const char* data1, int diarias1, const char* data2, int diarias2); // Verifica se duas locações conflitam

extern Locacao locacoes[MAX_LOCACOES]; // Declare a variável externa aqui
extern int contador_locacoes; // Declare a variável externa aqui

// void exibir_alerta_estender_locacao(int id_locacao) {
//     for (int i = 0; i < contador_locacoes; i++) {
//         if (locacoes[i].id == id_locacao) {
//             // Lógica para alertar admin sobre possível extensão
//             printf("⚠️ Locação ID %d com hóspede ID %d em breve poderá ser estendida.\n", 
//                    locacoes[i].id, locacoes[i].id_hospede);
//             return;
//         }
//     }
//     printf("Locação com ID %d não encontrada para alerta.\n", id_locacao);
// }


#endif // LOCACAO_H
