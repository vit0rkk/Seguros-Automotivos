#ifndef COTACAO_H
#define COTACAO_H
#include "veiculo.h"
#include "condutor.h"

typedef struct {
    Veiculo veiculo;
    Condutor condutor;
    float premio_anual;
    float premio_mensal;
    char data[11];
} Cotacao;

float calcular_taxa(Cotacao *c);
void calcular_premio(Cotacao *c);

#endif
