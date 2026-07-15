#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "veiculo.h"
#include "condutor.h"
#include "cotacao.h"
#include "arquivo.h"
#include "relatorio.h"

static int garantir_capacidade(Cotacao **lista, int quantidade, int *capacidade) {
    if (quantidade < *capacidade) {
        return 1;
}

    if (*capacidade == 0) {
        *capacidade = 1;
    } else {
        *capacidade *= 2;
    }

    Cotacao *temp = realloc(*lista, *capacidade * sizeof(Cotacao));

    if (temp == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }

    *lista = temp;
    return 1;
}

static void nova_cotacao(Cotacao **lista, int *quantidade, int *capacidade) {

    if (!garantir_capacidade(lista, *quantidade, capacidade))
        return;

    Cotacao c;

    cadastrar_veiculo(&c.veiculo);
    cadastrar_condutor(&c.condutor);

    calcular_premio(&c);

    /* Salva a data da cotação */
    time_t t = time(NULL);
    struct tm *hoje = localtime(&t);
    strftime(c.data, sizeof(c.data), "%d/%m/%Y", hoje);

    (*lista)[*quantidade] = c;
    (*quantidade)++;

    printf("\n===========================================\n");
    printf("Cotacao cadastrada com sucesso!\n");
    printf("Premio anual : R$ %.2f\n", c.premio_anual);
    printf("Premio mensal: R$ %.2f\n", c.premio_mensal);
    printf("===========================================\n");
}

static void mostrar_menu(void) {

    printf("\n");
    printf("=========================================================\n");
    printf("        SISTEMA DE COTACAO DE SEGUROS AUTOMOTIVOS\n");
    printf("=========================================================\n\n");

    printf("                MENU PRINCIPAL\n\n");

    printf("  [1] Nova cotacao\n");
    printf("  [2] Listar todas as cotacoes\n");
    printf("  [3] Filtrar por nome do condutor\n");
    printf("  [4] Exibir menor cotacao\n");
    printf("  [5] Salvar cotacoes\n");
    printf("  [0] Salvar e sair\n");

    printf("\n---------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main(void) {

    Cotacao *lista = NULL;
    int quantidade = 0;
    int capacidade = 0;
    int opcao;

    lista = carregar_dados("cotacoes.dat", sizeof(Cotacao), &quantidade);

    if (lista != NULL) {
        capacidade = quantidade;
        printf("\n%d cotacao(oes) carregada(s).\n", quantidade);
    }

    do {

        mostrar_menu();

        if (scanf("%d", &opcao) != 1) {
            
            if (feof(stdin)) {
    printf("\nEntrada finalizada. Encerrando...\n");
    break;
}

            while (getchar() != '\n');

            printf("\nOpcao invalida!\n");

            continue;
        }

        if (feof(stdin)) {
    printf("\nEntrada finalizada. Encerrando...\n");
    break;
}

        while (getchar() != '\n');

        switch (opcao) {

            case 1:

                nova_cotacao(&lista, &quantidade, &capacidade);

                break;

            case 2:

                listar_todas(lista, quantidade);

                break;

            case 3: {

                char nome[100];

                printf("\nDigite o nome do condutor: ");

                fgets(nome, sizeof(nome), stdin);

                nome[strcspn(nome, "\n")] = '\0';

                filtro_condutor(lista, quantidade, nome);

                break;
            }

            case 4:

                menor_valor(lista, quantidade);

                break;

            case 5:

                if (salvar_dados("cotacoes.dat",
                                 lista,
                                 sizeof(Cotacao),
                                 quantidade))

                    printf("\nDados salvos com sucesso!\n");

                else

                    printf("\nErro ao salvar os dados!\n");

                break;

            case 0:

                salvar_dados("cotacoes.dat",
                             lista,
                             sizeof(Cotacao),
                             quantidade);

                printf("\nDados salvos.\n");
                printf("Encerrando o programa...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

        if (opcao != 0) {

            printf("\nPressione ENTER para continuar...");

            getchar();
        }

    } while (opcao != 0);

    free(lista);

    return 0;
}