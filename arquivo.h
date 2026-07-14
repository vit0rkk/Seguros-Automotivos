#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>

int salvar_dados(const char *nome_arquivo, void *lista, size_t tamanho_item, int total);
void* carregar_dados(const char *nome_arquivo, size_t tamanho_item, int *total_lidos);

#endif

