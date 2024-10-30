#ifndef RESERVA_H
#define RESERVA_H

#define MAX_RESERVAS 100

typedef struct {
    int id;
    int id_hospede;
    int id_quarto;
    char data_entrada[11];
    char data_saida[11];
} Reserva;

void adicionar_reserva_antecipada(Reserva nova_reserva);
void listar_reservas_antecipadas();
int get_contador_reservas();
void menu_adicionar_reserva();
void salvar_reservas_no_arquivo();
void carregar_reservas_do_arquivo();
int editar_reserva(int id, Reserva reserva_editada);
int excluir_reserva(int id);

#endif
