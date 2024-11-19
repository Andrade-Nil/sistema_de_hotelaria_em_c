#ifndef UTIL_H
#define UTIL_H
#define _XOPEN_SOURCE 700  // Definindo a versão correta antes de incluir os cabeçalhos
#include <time.h>


int validar_data(const char* data);
int calcular_dias_entre_datas(char* data_inicial, char* data_final);
void verificar_arquivos();
int diferenca_dias(const char* data1, const char* data2); // Adicione em util.h


#endif
