#ifndef UTIL_H
#define UTIL_H
#define _XOPEN_SOURCE 700  // Definindo a versão correta antes de incluir os cabeçalhos
#include <time.h>


int validar_data(const char* data);
int calcular_dias_entre_datas(char* data_inicial, char* data_final);
void verificar_arquivos();

#endif
