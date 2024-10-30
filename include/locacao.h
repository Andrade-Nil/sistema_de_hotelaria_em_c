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
void listar_locacoes(); // Função para listar locações
void gerenciar_locacoes();

extern Locacao locacoes[MAX_LOCACOES]; // Declare a variável externa aqui
extern int contador_locacoes; // Declare a variável externa aqui

#endif // LOCACAO_H
