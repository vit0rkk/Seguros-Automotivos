#ifndef VEICULO_H
#define VEICULO_H

typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
    float valor_mercado;
    char tipo; // Se eh tipo P, U ou E
} Veiculo;

void cadastrar_veiculo(Veiculo *v);

#endif

