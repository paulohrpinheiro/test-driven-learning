# Test Driven Learning - Juniores

Estamos em uma nova fase. Agora somos juniores. Temos que construir um
*software*, na verdade uma biblioteca, que salve dados em disco. Serão
registros de tamanho fixo, com campos de tamanho fixo.

## Estrutura

Cada __tabela__ conterá dois arquivos. Um com a definição dos campos, outro com
os dados.

O arquivo com campos terá a forma `NOME.def` e o arquivo com dados a
forma `NOME.dat`.

O arquivo de definições terá uma ou mais linhas com a seguinte forma:

    NOME_CAMPO, TIPO_CAMPO, TAMANHO_CAMPO


Ou seja, cada tupla (NOME_CAMPO, TIPO_CAMPO, TAMANHO_CAMPO) deve ser seguido de
um caracter '\n'.


## Interface

Nossa *interface* deve prover um objeto, em cuja inicialização seja passado o
parâmetro com o __NOME__, e o caminho. A partir dessas informações, esse
objeto abre o arquivo e faz algumas verificações, para certificar-se que os
dados não estão corrompidos, ao menos em sua estrutura.

A interface deve prover esses métodos públicos:

* __create__
* __read__
* __update__
* __delete__

## Métodos

* create

    Recebe como parâmetros os dados e os insere no arquivo e retorna
    o número do registro.

* read

    Recebe um número inteiro referente ao número do registro, e devolve os
    dados.

* update

    Recebe um um número inteiro referente ao número do registro e os dados a
    alterar. Localiza no arquivo o registro e realiza as alterações.

* delete

    Recebe um número inteiro referente ao número do registro. Localiza no
    arquivo o registro e marca como apagado (deixa tudo com espaços).
