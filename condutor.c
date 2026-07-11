#include "condutor.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funcao pra limpar o buffer do teclado
static void limpar_buffer_condutor() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao pra validar o RG
static int validar_rg(char *rg) {
    if (strlen(rg) != 5) {
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (!isdigit(rg[i])) {
            return 0;
        }
    }
    return 1;
}

// Funcao pra validar a categoria da CNH
static int validar_cnh(char cnh) {
    cnh = toupper(cnh);
    return (cnh == 'A' || cnh == 'B' || cnh == 'C');
}

void cadastrar_condutor(Condutor *c) {
    printf("\nPerfil do Condutor\n");
    
    printf("Nome completo: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    // se o nome for maior que o array limpa o resto que sobrou no buffer
    if (c->nome[strcspn(c->nome, "\n")] == '\0' && strlen(c->nome) == sizeof(c->nome) - 1) {
        limpar_buffer_condutor();
    } else {
        c->nome[strcspn(c->nome, "\n")] = 0;
    }

    do {
        printf("RG (exatamente 5 digitos): ");
        fgets(c->rg, sizeof(c->rg), stdin);
        
        // se digitar mais de 5 ele limpa o excesso
        if (c->rg[strcspn(c->rg, "\n")] == '\0' && strlen(c->rg) == sizeof(c->rg) - 1) {
            limpar_buffer_condutor();
        } else {
            c->rg[strcspn(c->rg, "\n")] = 0;
        }

        if (!validar_rg(c->rg)) {
            printf("Erro: O RG deve conter exatamente 5 numeros.\n");
        }
    } while (!validar_rg(c->rg));

    do {
        printf("Idade: ");
        if (scanf("%d", &c->idade) != 1 || c->idade < 18 || c->idade > 120) {
            printf("Erro: Idade invalida para condutor (minimo 18 anos).\n");
            c->idade = 0;
        }
        limpar_buffer_condutor(); // movi os buffer pra limpar o \n
    } while (c->idade == 0);

    do {
        printf("Numero de sinistros nos ultimos 3 anos: ");
        if (scanf("%d", &c->sinistros) != 1 || c->sinistros < 0) {
            printf("Erro: Digite um numero valido de sinistros.\n");
            c->sinistros = -1;
        }
        limpar_buffer_condutor();
    } while (c->sinistros < 0);

    do {
        printf("Categoria da CNH (A / B / C): ");
        scanf(" %c", &c->cnh);
        c->cnh = toupper(c->cnh);
        limpar_buffer_condutor(); //limpa dps do scanf pra nao dar problema em cadastro futuro
        
        if (!validar_cnh(c->cnh)) {
            printf("Erro: Categoria invalida! Digite A, B ou C.\n");
        }
    } while (!validar_cnh(c->cnh));
}
