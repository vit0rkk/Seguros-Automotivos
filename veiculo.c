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
    printf("\nCadastro do Veiculo\n");
    
    printf("Marca: ");
    fgets(v->marca, sizeof(v->marca), stdin);
    //limpar o resto que sobrou do buffer se a marca for maio que o array
    if(v->marca[strcspn(v->marca, "\n")] == '\0' && strlen(v->marca) == sizeof(v->marca) - 1) {
        limpar_buffer_veiculo();
    } else {
        v->marca[strcspn(v->marca, "\n")] = 0;
    }

    printf("Modelo: ");
    fgets(v->modelo, sizeof(v->modelo), stdin);
    if(v->modelo[strcspn(v->modelo, "\n")] == '\0' && strlen(v->modelo) == sizeof(v->modelo) - 1) {
        limpar_buffer_veiculo();
    } else {
        v->modelo[strcspn(v->modelo, "\n")] = 0;
    }

    do {
        printf("Ano de fabricacao: ");
        if (scanf("%d", &v->ano) != 1 || v->ano < 1886) {
            printf("Erro: Ano invalido.\n");
            v->ano = 0;
        }
        limpar_buffer_veiculo(); //mudei tanto aqui quanto no condutor
    } while (v->ano == 0);

    do {
        printf("Valor de mercado (R$): ");
        if (scanf("%f", &v->valor_mercado) != 1 || v->valor_mercado <= 0) {
            printf("Erro: Valor deve ser maior que zero.\n");
            v->valor_mercado = 0;
        }
        limpar_buffer_veiculo();
    } while (v->valor_mercado <= 0);

    do {
        printf("Tipo [(P) Passeio / (U) Utilitario / (E) Esportivo]: ");
        scanf(" %c", &v->tipo);
        v->tipo = toupper(v->tipo);
        limpar_buffer_veiculo();
        if (!validar_tipo_veiculo(v->tipo)) {
            printf("Erro: Tipo invalido! Digite P, U ou E.\n");
        }
    } while (!validar_tipo_veiculo(v->tipo));

    limpar_buffer_veiculo();
}

