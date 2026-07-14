#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "condutor.h"
#include "cotacao.h"

static int garantir_capacidade(Cotacao **lista, int quantidade, int *capacidade) {
    if (quantidade < *capacidade) {
        return 1;  //ainda nao chegou na capacidade maxima
    }

    if(*capacidade == 0){
        *capacidade = 1; 
    } else{
        *capacidade *= 2;
    }

    int nova_capacidade = *capacidade;
    
    Cotacao *temp = realloc(*lista, *capacidade * sizeof(Cotacao));

    if (temp == NULL) { //verifica se a memoria foi alocada com sucesso
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }

    *lista = temp;
    *capacidade = nova_capacidade;
    return 1;
}

static void nova_cotacao(Cotacao **lista, int *quantidade, int *capacidade) {
    if (!garantir_capacidade(lista, *quantidade, capacidade)) {
        return;
    }

    Cotacao c;

    cadastrar_veiculo(&c.veiculo);
    cadastrar_condutor(&c.condutor);
    calcular_premio(&c);

    (*lista)[*quantidade] = c;
    (*quantidade)++;

    printf("Cotacao cadastrada com sucesso! Premio anual: %.2f\n", c.premio_anual);
}

