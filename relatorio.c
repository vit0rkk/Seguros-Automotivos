#include <stdio.h>
#include <string.h>
#include "relatorio.h"

static void imprimir_cotacao(Cotacao *c, int indice){
    printf("======================================================\n");
    printf("\n\tCOTACAO %d  -  Data: %s\n\n", indice + 1, c->data);
    printf("\nCONDUTOR:\n\n    Nome:\t%s\n    RG:\t    %s  |  Idade:\t  %d anos\n    CNH:\t%c  |  Sinistros:\t%d\n\n", c->condutor.nome, c->condutor.rg, c->condutor.idade, c->condutor.cnh, c->condutor.sinistros);

    printf("\nVEICULO:\n\n    Modelo:\t%s %s (%d)\n    Tipo:\t%c  |  Valor de Mercado:\tR$ %.2f\n\n", c->veiculo.marca, c->veiculo.modelo, c->veiculo.ano, c->veiculo.tipo, c->veiculo.valor_mercado);

    printf("\nVALORES DO SEGURO:\n\n    Premio Anual:\tR$ %.2f\n    Premio Mensal:\tR$ %.2f\n\n", c->premio_anual, c->premio_mensal);
    printf("======================================================\n\n");
}
void listar_todas(Cotacao *lista, int total){
    if(lista == NULL || total == 0){
        printf("\n\tNenhuma cotacao cadastrada\n\n");
        return;
    }
    printf("\n\t// LISTAGEM DE TODAS AS COTACOES \\\\ \n\n");
    for(int i = 0; i < total; i++){
        imprimir_cotacao(&lista[i], i);
    }
}

void filtro_condutor(Cotacao *lista, int total, char *nome_busca){
    if(lista == NULL || total == 0){
        printf("\n\tNenhuma cotacao cadastrada para busca\n\n");
        return;
    }
    int encontrados = 0;
    printf("\n\t// RESULTADOS DA BUSCA POR: %s \\\\ \n\n", nome_busca);

    for(int i = 0; i < total; i++){
        if(strstr(lista[i].condutor.nome, nome_busca) != NULL){
            imprimir_cotacao(&lista[i], i);
            encontrados++;
        }
    }

    if(encontrados == 0){
        printf("\n\tNenhum condutor cadastrado com o Nome:  %s\n\n", nome_busca);
    }else{
        printf("\n\tTOTAL DE REGISTROS ENCONTRADOS: %d\n\n", encontrados);
    }
}

void menor_valor(Cotacao *lista, int total){
    if(lista == NULL || total == 0){
        printf("\n\tNenhuma cotacao cadastrada para exibir o menor valor\n\n");
        return;
    }

    int menor_indice = 0;
    float menor_valor = lista[0].premio_anual;

    for(int i = 1; i < total; i++){
        if(lista[i].premio_anual < menor_valor){
            menor_valor = lista[i].premio_anual;
            menor_indice = i;
        }
    }

    printf("\n\t// COTACAO DE MENOR VALOR \\\\ \n\n");
    imprimir_cotacao(&lista[menor_indice], menor_indice);
}
