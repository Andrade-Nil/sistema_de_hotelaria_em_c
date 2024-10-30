#ifndef HOSPEDE_H
#define HOSPEDE_H

#define MAX_HOSPEDES 100

typedef struct {
    int id;
    char nome[100];
    char contato[50];
} Hospede;

extern Hospede hospedes[MAX_HOSPEDES];
extern int contador_hospedes;

int adicionar_hospede(); // Função para adicionar novo hóspede
int listar_hospedes();   // Função para listar hóspedes
int gerenciar_hospedes(); // Função de gerenciamento

// Funções de manipulação de arquivo
int carregar_hospedes(); // Carrega dados do arquivo
int salvar_hospedes();   // Salva dados no arquivo

#endif
