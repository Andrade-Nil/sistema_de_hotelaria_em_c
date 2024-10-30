#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define _XOPEN_SOURCE 700  // Definindo a versão correta antes de incluir os cabeçalhos
#include <time.h>
#include "../include/util.h"

// Função para validar a data no formato "YYYY-MM-DD"
int validar_data(const char* data) {
    struct tm tm = {0};  // Inicializando a estrutura tm
    char* result = strptime(data, "%Y-%m-%d", &tm);

    // Verifica se o resultado é nulo e se o restante da string foi consumido
    return (result != NULL && *result == '\0'); // Retorna 1 se a data for válida, 0 caso contrário
}

// Função para verificar e criar arquivos de dados, se necessário
void verificar_arquivos() {
    struct stat st = {0};

    // Verificar se a pasta "data" existe, se não, criar a pasta
    if (stat("../data", &st) == -1) {
        if (mkdir("../data", 0700) != 0) {
            perror("Erro ao criar diretório 'data'");
            exit(EXIT_FAILURE);
        }
        printf("Diretório 'data' criado com sucesso.\n");
    }

    const char *arquivos[] = {
        "../data/quartos.txt",
        "../data/hospedes.txt",
        "../data/locacoes.txt",
        "../data/reservas.txt"
    };

    for (int i = 0; i < sizeof(arquivos) / sizeof(arquivos[0]); i++) {
        FILE *file = fopen(arquivos[i], "a");  // Usando "a" para não sobrescrever dados existentes
        if (file == NULL) {
            perror("Erro ao criar arquivo");
            exit(EXIT_FAILURE);
        }
        fclose(file);
        printf("Arquivo '%s' verificado ou criado com sucesso.\n", arquivos[i]);
    }
}
