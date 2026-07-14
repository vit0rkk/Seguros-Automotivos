#ifndef RELATORIO_H
#define RELATORIO_H

#include "cotacao.h"

void listar_todas(Cotacao *lista, int total);
void filtro_condutor(Cotacao *lista, int total, char *nome_busca);
void menor_valor(Cotacao *lista, int total);

#endif
