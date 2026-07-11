# Sistema de Cotação Automática de Seguros Automotivos

## Integrantes
- Vitor Hugo Martins de Moraes <br>
- Ana Cecília da Silva Ferreira <br>
- Bruno Costa Amorim <br>
- Maria Eduarda Santos Montel <br>
- Andressa Carvalho de Sousa <br>
- Gabriel Luca Santos Costa <br>

## Descrição do sistema
Este sistema foi desenvolvido em linguagem C para realizar o cadastro e a cotação automática de seguro de veículos por linha de comando. Ele permite registrar informações do veículo e do condutor, calcular o valor do prêmio anual e mensal com base em regras de negócio específicas e armazenar as cotações em arquivo para consulta posterior.

O programa considera fatores como tipo do veículo, ano de fabricação, idade do condutor, quantidade de sinistros e categoria da CNH para determinar o valor final do seguro. Além disso, oferece funcionalidades para listar todas as cotações salvas, filtrar registros por nome do condutor e identificar a cotação de menor valor entre as cadastradas.

## Estrutura do projeto
O projeto foi estruturado com foco em conceitos fundamentais da linguagem C, como uso de `structs`, manipulação de ponteiros, alocação dinâmica de memória, leitura e escrita em arquivos e modularização em múltiplos arquivos `.c` e `.h`. Também inclui validação de entradas para garantir maior robustez durante o uso.
