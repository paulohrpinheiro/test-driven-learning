# Test Drive Learning - *000_novice*

O objetivo nessa primeira fase é apresentar a proposta e resolver problemas
muito simples.

Na [branch
master](https://github.com/paulohrpinheiro/test-driven-learning/tree/master)
estão os problemas, e na [branch solved](https://github.com/paulohrpinheiro/test-driven-learning/tree/solved)
uma solução.


## PROBLEMA 1

    A função `negue` deve receber um valor boleano (verdadeiro ou falso) e
    retornar a negação desse valor.

* negue(verdadeiro) -> falso
* negue(falso) -> verdadeiro


## PROBLEMA 2

    A função `diga_ola` deve ser escrita de tal forma que receba como
    parâmetro um argumento *string*. Deve retornar a *string* "Olá, ", seguida
    do argumento recebido, mais um ponto final. A *string* recebida deve estar
    limpa, ou seja, sem caracteres de espaço no começo ou no fim. Se a *string*
    estiver vazia, retorna apenas "Olá!"

* diga_ola('') -> 'Olá!'
* diga_ola('    ') -> 'Olá!'
* diga_ola('Paulo') -> 'Olá, Paulo.'
* diga_ola('  Paulo  ') -> 'Olá, Paulo.'


## PROBLEMA 3

    A função `lista_numeros_pares` deve receber um parâmetro numérico
    inteiro que determina quantos números pares devem estar em um array que
    será o retorno da função.

* lista_numeros_pares(0) -> []
* lista_numeros_pares(1) -> ['2']
* lista_numeros_pares(4) -> ['2', '4', '6', '8']
* lista_numeros_pares(5) -> ['2', '4', '6', '8', '10']
* lista_numeros_pares(-1) -> []


## PROBLEMA 4

    A função `lista_multiplos` deve receber dois parâmetros numéricos
    inteiros e retornar uma lista de números inteiros. O tamanho da lista é
    determinado pelo primeiro parâmetro, e o número base será o segundo
    parâmetro.


* lista_multiplos(0, 10) -> []
* lista_multiplos(-1, 10) -> []
* lista_multiplos(3, -1) -> ['-3', '-2', '-1']
* lista_multiplos(3, 0) -> []
* lista_multiplos(3, 10) -> ['10', '20', '30']


## PROBLEMA 5

    A função `soma` deve receber um *array* de números inteiros, e retornar
    a sua soma. Se a lista for vazia, deve retornar zero.


* soma([]) -> 0
* soma([1]) -> 1
* soma([1, 2]) -> 3


## PROBLEMA 6

    A função `subtracao` deve receber um *array* de números inteiros, e
    retornar a subtração de todos os elementos em sequência. Por exemplo,
    subtracao([3,2,1]) deve retornar 0, e subtracao([10,2,3]) deve retornar 5.
    Se a lista for vazia, deve retornar zero.

* subtracao([3, 2, 1]) -> 0
* subtracao([10, 2, 3]) -> 5
* subtracao([]) -> 0
* subtracao([1, 2]) -> -1
* subtracao([-1, -2, -3]) -> 4
* subtracao([9, 3, 2, 1]) -> 3


## PROBLEMA 7

    A função `multiplicação` deve receber um *array* de números inteiros, e
    retornar o seu produto. Se a lista for vazia, deve retornar zero.

* multiplicacao([1, 2, 3]) -> 6
* multiplicacao([]) -> 0
* multiplicacao([-2, 1, 4]) -> -8
* multiplicacao([-2, -1, 4]) -> 8


## PROBLEMA 8

    A função `divisao` deve receber um *array* de números inteiros, e
    retornar o resultado da sequência de divisões por cada elemento. Por
    exemplo, divisão([16, 4, 2]) deve retornar 2, e divisão([100,2,10]) deve
    retornar 5. Se a lista for vazia, deve retornar zero.

* divisao([5, 2]) -> 2
* divisao([]) -> 0
* divisao([0]) -> 0
* divisao([0, 1]) -> 0
* divisao([1, 0]) -> deve gerar um erro/exceção


## PROBLEMA 9

    A função `operacao` deve receber dois parâmetros. O primeiro parâmetro é
    um caractere indicando a operação aritmética básica a ser realizada ('+',
    '-', '\*', '/'). O segundo parâmetro é um *array* de números inteiros, para
    os quais a operação deve ser aplicada. A função deve retornar o resultado
    da operação no *array*. Chame as funções já criadas para cada operação. Em
    caso de operação inválida, gere uma exceção.

* operacao('+', [1, 2]) -> 3
* operacao('-', [1, 2]) -> -1
* operacao('\*', [1, 2]) -> 2
* operacao('/', [1, 2]) -> 0
* operacao('=', [1, 2]) -> deve gerar um erro/exceção


## PROBLEMA 10

    A função `maior` deve receber um  *array* de números inteiros e retornar
    qual é o maior deles.

* maior([0, 1 ,100]) -> 100
* maior([0]) -> 0
* maior([]) -> deve gerar um erro/exceção


## PROBLEMA 11

    A função `intersecao` deve receber dois *arrays* contendo números
    inteiros, e retornar a interseção entre os conjuntos, ou seja, um *array*
    que contenha apenas os números que estejam contidos nos dois *arrays*
    passados para a função.

* intersecao([], []) -> []
* intersecao([1, 2], [3, 4]) -> []
* intersecao([1, 2], [2, 3]) -> [2]
