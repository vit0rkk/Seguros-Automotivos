#include "cotacao.h"
#include <time.h>

static int limitar_sinistros(int sinistros) {
    if (sinistros > 3)
        return 3;
    return sinistros;
}

float calcular_taxa(Cotacao *c) {
    float taxa = 0.04f;

    time_t t = time(NULL);
    struct tm *data = localtime(&t);
    int ano_atual = data->tm_year + 1900;

    if ((ano_atual - c->veiculo.ano) <= 3)
        taxa += 0.015f;

    if (c->condutor.idade < 25)
        taxa += 0.020f;

    if (c->condutor.idade >= 65)
        taxa += 0.010f;

    taxa += limitar_sinistros(c->condutor.sinistros) * 0.015f;

    if (c->condutor.cnh == 'C')
        taxa -= 0.005f;

    return taxa;
}

void calcular_premio(Cotacao *c) {
    float taxa = calcular_taxa(c);

    c->premio_anual = c->veiculo.valor_mercado * taxa;

    if (c->veiculo.tipo == 'E')
        c->premio_anual *= 1.4f;

    c->premio_mensal = c->premio_anual / 12.0f;
}

