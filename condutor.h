#ifndef CONDUTOR_H
#define CONDUTOR_H

typedef struct {
	char nome[100];
	char rg[6]; //os cinco mais o '\0'
	int idade;
	int sinistros;
	char cnh; //se eh a, b ou c
} Condutor;

void cadastrar_condutor(Condutor *c);

#endif
