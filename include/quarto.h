#ifndef QUARTO_H
#define QUARTO_H

#define MAX_QUARTOS 100

typedef struct {
    int id;
    char tipo[50];
    float valor_diaria;
} Quarto;

extern Quarto quartos[MAX_QUARTOS];
extern int contador_quartos;

int adicionar_quarto(const char *tipo, float valor_diaria);
int listar_quartos();
void gerenciar_quartos();

// Funções para manipular o arquivo
int salvar_quartos();
int carregar_quartos();
int atualizar_quarto(int id, const char *novo_tipo, float novo_valor_diaria);
int excluir_quarto(int id);

#endif
