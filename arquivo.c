#include "arquivo.h"

int salvar_dados(const char *nome_arquivo, void *lista, size_t tamanho_item, int total) {
    if (lista == NULL || nome_arquivo == NULL) return 0;

    FILE *f = fopen(nome_arquivo, "wb");
    if (f == NULL) return 0;

    
    size_t gravados = fwrite(lista, tamanho_item, total, f);

    fclose(f);
    return (gravados == (size_t)total);
}

void* carregar_dados(const char *nome_arquivo, size_t tamanho_item, int *total_lidos) {
    if (nome_arquivo == NULL || total_lidos == NULL) {
        if (total_lidos) *total_lidos = 0;
        return NULL;
    }

    FILE *f = fopen(nome_arquivo, "rb");
    if (f == NULL) {
        *total_lidos = 0;
        return NULL;
    }
    
    int capacidade = 2;
    int quantidade = 0;

    void *dados = malloc(capacidade * tamanho_item);
    if (dados == NULL) {
        fclose(f);
        *total_lidos = 0;
        return NULL;
    }

    
    while (1) {
        
        if (quantidade >= capacidade) {
            capacidade *= 2;
            void *temp = realloc(dados, capacidade * tamanho_item);
            if (temp == NULL) {
                free(dados); 
                fclose(f);
                *total_lidos = 0;
                return NULL;
            }
            dados = temp;
        }

        
        void *posicao_escrita = (char*)dados + (quantidade * tamanho_item);

        if (fread(posicao_escrita, tamanho_item, 1, f) != 1) {
            break; 
        }

        quantidade++;
    }

    fclose(f);

    
    if (quantidade > 0) {
        void *temp = realloc(dados, quantidade * tamanho_item);
        if (temp != NULL) {
            dados = temp;
        }
    } else {
        
        free(dados);
        dados = NULL;
    }

    *total_lidos = quantidade;
    return dados;
}