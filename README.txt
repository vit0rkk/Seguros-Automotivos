## Integrantes
- Vitor Hugo Martins de Moraes <br>
- Ana Cecília da Silva Ferreira <br>
- Bruno Costa Amorim <br>
- Maria Eduarda Santos Montel <br>
- Andressa Carvalho de Sousa <br>
- Gabriel Luca Santos Costa <br>

# Sistema de Cotação Automática de Seguros Automotivos

Sistema de linha de comando em C que cadastra veículo e condutor, calcula o
prêmio do seguro conforme as regras de negócio do enunciado e persiste as
cotações em arquivo binário (`cotacoes.dat`).

## Como compilar

```bash
make
```

compilar sem make:

```bash
gcc -Wall -Wextra -o cotacao *.c
```

## Como executar

```bash
./cotacao
```

O programa carrega automaticamente `cotacoes.dat` (se existir) ao iniciar, e
oferece um menu com as opções:

1. Nova cotação (cadastra veículo + condutor e calcula o prêmio)
2. Listar todas as cotações
3. Filtrar por nome do condutor
4. Exibir cotação de menor valor
5. Salvar cotações em arquivo
0. Salvar e sair

## Como limpar os binários

```bash
make clean
```

## Regras de negócio (resumo)

- Taxa base: 4% do valor de mercado do veículo ao ano
- +1,5% se o veículo tiver até 3 anos de fabricação
- +2,0% se o condutor tiver menos de 25 anos, ou +1,0% se tiver 65 anos ou mais
- +1,5% por sinistro nos últimos 3 anos (máximo de 3 sinistros contabilizados)
- -0,5% se a CNH for categoria C
- Veículos do tipo Esportivo (E) têm o prêmio final multiplicado por 1,4