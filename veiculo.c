#include "veiculo.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funcao pra limpar o buffer do teclado rapeize
static void limpar_buffer_veiculo() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao pra validar o tipo do carro rapeize
static int validar_tipo_veiculo(char t) {
    t = toupper(t);
    return (t == 'P' || t == 'U' || t == 'E');
}

void cadastrar_veiculo(Veiculo *v) {
    printf("=== CADASTRO DO VEICULO ===\n");
    
    printf("Marca: ");
    fgets(v->marca, sizeof(v->marca), stdin);
    v->marca[strcspn(v->marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(v->modelo, sizeof(v->modelo), stdin);
    v->modelo[strcspn(v->modelo, "\n")] = 0;

    do {
        printf("Ano de fabricacao: ");
        if (scanf("%d", &v->ano) != 1 || v->ano < 1886) {
            printf("Erro: Ano invalido.\n");
            limpar_buffer_veiculo();
            v->ano = 0;
        }
    } while (v->ano == 0);

    do {
        printf("Valor de mercado (R$): ");
        if (scanf("%f", &v->valor_mercado) != 1 || v->valor_mercado <= 0) {
            printf("Erro: Valor deve ser maior que zero.\n");
            limpar_buffer_veiculo();
            v->valor_mercado = 0;
        }
    } while (v->valor_mercado <= 0);

    do {
        printf("Tipo [(P) Passeio / (U) Utilitario / (E) Esportivo]: ");
        scanf(" %c", &v->tipo);
        v->tipo = toupper(v->tipo);
        if (!validar_tipo_veiculo(v->tipo)) {
            printf("Erro: Tipo invalido! Digite P, U ou E.\n");
        }
    } while (!validar_tipo_veiculo(v->tipo));

    limpar_buffer_veiculo();
}

