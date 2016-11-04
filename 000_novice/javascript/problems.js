// Test Driven Learning Project.
// Desenvolva TDD e programação com TDD e programação!
// Módulo novice.
//
// The MIT License (MIT)
//
// Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulohrpinheiro@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


pass = 0;
fail = 0;


// Este é o nosso framwork de testes para javascript :)

function doPass(message) {
    pass++;
    print(message + ': PASS');
}

function doFail(message) {
    fail++;
    print(message + ': FAIL');
}

function assert(functionRef, functionParameters, expected, description) {
    if(JSON.stringify(functionRef.apply(null, functionParameters)) === JSON.stringify(expected)) {
        doPass(description);
    }
    else {
        doFail(description);
    }
};


// Aqui estão as funcções para trabalharmos

function assertAnyException(functionRef, functionParameters, description) {
    try {
        functionRef.apply(null,functionParameters);
        doFail(description);
    }
    catch(e) {
        doPass(description);
    }
}

function negue(x) {
//A função `negue` deve receber um valor boleano (verdadeiro ou falso) e
//    retornar a negação desse valor.

    /* coloque aqui o seu código */

    return !x;
}

assert(negue, [true]  , false , 'negue_001');
assert(negue, [false] , true  , 'negue_002');


function diga_ola(nome) {
//  A função `diga_ola` deve ser escrita de tal forma que receba como
//    parâmetro um argumento *string*. Deve retornar a *string* "Olá, ", seguida
//    do argumento recebido, mais um ponto final. A *string* recebida deve estar
//    limpa, ou seja, sem caracteres de espaço no começo ou no fim. Se a *string*
//    estiver vazia, retorna apenas "Olá!"

    /* coloque aqui o seu código */

    var nomeSemEspacos = nome.trim();

    if (!nomeSemEspacos) {
        return "Olá!";
    }
    else {
        return "Olá, " + nomeSemEspacos + ".";
    }
}

assert(diga_ola, [""]         , "Olá!"       , 'diga_ola_001');
assert(diga_ola, ["Paulo"]    , "Olá, Paulo.", 'diga_ola_002');
assert(diga_ola, ["  Paulo  "], "Olá, Paulo.", 'diga_ola_003');


function lista_numeros_pares(quantos) {
//  A função `lista_numeros_pares` deve receber um parâmetro numérico
//    inteiro que determina quantos números pares devem estar em um array que
//    será o retorno da função.

    /* coloque aqui o seu código */

    var pares = [];

    for(var i=1; i<=quantos; i++) {
        pares.push(i*2);
    }

    return pares;
}

assert(lista_numeros_pares, [ 0], []              , 'lista_numeros_pares_001');
assert(lista_numeros_pares, [ 1], [2]             , 'lista_numeros_pares_002');
assert(lista_numeros_pares, [ 4], [2, 4, 6, 8]    , 'lista_numeros_pares_003');
assert(lista_numeros_pares, [ 5], [2, 4, 6, 8, 10], 'lista_numeros_pares_004');
assert(lista_numeros_pares, [-1], []              , 'lista_numeros_pares_005');


function lista_multiplos(quantos, base) {
//  A função `lista_multiplos` deve receber dois parâmetros numéricos
//    inteiros e retornar uma lista de números inteiros. O tamanho da lista é
//    determinado pelo primeiro parâmetro, e o número base será o segundo
//    parâmetro.

    /* coloque aqui o seu código */

    if(base===0||quantos===0) {
        return [];
    }

    var multiplos = [];

    for(var i=1; i<=quantos; i++) {
        multiplos.push(base*i);
    }

    // Em caso de base negativa
    multiplos.sort(function (a, b) {  return a - b;  });

    return multiplos;
}

assert(lista_multiplos, [ 0, 10], []          , 'lista_multiplos_001');
assert(lista_multiplos, [-1, 10], []          , 'lista_multiplos_002');
assert(lista_multiplos, [ 3, -1], [-3, -2, -1], 'lista_multiplos_003');
assert(lista_multiplos, [ 3,  0], []          , 'lista_multiplos_004');
assert(lista_multiplos, [ 3, 10], [10, 20, 30], 'lista_multiplos_005');


function soma(inteiros) {
//  A função `soma` deve receber um *array* de números inteiros, e retornar
//    a sua soma. Se a lista for vazia, deve retornar zero.

    /* coloque aqui o seu código */

    var resultadoSoma = 0;

    for(var i=0; i<inteiros.length; i++) {
        resultadoSoma += inteiros[i];
    }

    return resultadoSoma;
}

assert(soma, [[]]   , 0, 'soma_001');
assert(soma, [[1]]  , 1, 'soma_002');
assert(soma, [[1,2]], 3, 'soma_003');


function subtracao(inteiros) {
//  A função `subtracao` deve receber um *array* de números inteiros, e
//    retornar a subtração de todos os elementos em sequência. Por exemplo,
//    subtracao([3,2,1]) deve retornar 0, e subtracao([10,2,3]) deve retornar 5.
//    Se a lista for vazia, deve retornar zero.

    /* coloque aqui o seu código */

    if(inteiros.length===0) {
        return 0;
    }

    var resultadoSubtracao = inteiros[0];

    for(var i=1; i<inteiros.length; i++) {
        resultadoSubtracao -= inteiros[i];
    }

    return resultadoSubtracao;
}

assert(subtracao, [[3, 2, 1]]   ,  0, 'subtracao_001');
assert(subtracao, [[10, 2, 3]]  ,  5, 'subtracao_002');
assert(subtracao, [[]]          ,  0, 'subtracao_003');
assert(subtracao, [[1, 2]]      , -1, 'subtracao_004');
assert(subtracao, [[-1, -2, -3]],  4, 'subtracao_005');


function multiplicacao(inteiros) {
//  A função `multiplicação` deve receber um *array* de números inteiros, e
//    retornar o seu produto. Se a lista for vazia, deve retornar zero.

    /* coloque aqui o seu código */

    if(inteiros.length===0) {
        return 0;
    }

    var resultadoMultiplicacao = 1;

    for(var i=0; i<inteiros.length; i++) {
        resultadoMultiplicacao *= inteiros[i];
    }

    return resultadoMultiplicacao;
}

assert(multiplicacao, [[1, 2, 3]]   ,  6, 'multiplicacao_001');
assert(multiplicacao, [[]]          ,  0, 'multiplicacao_002');
assert(multiplicacao, [[-2, 1, 4]]  , -8, 'multiplicacao_003');
assert(multiplicacao, [[-2, -1, -4]], -8, 'multiplicacao_004');


function divisao(inteiros) {
//   A função `divisao` deve receber um *array* de números inteiros, e
//    retornar o resultado da sequência de divisões por cada elemento. Por
//    exemplo, divisão([16, 4, 2]) deve retornar 2, e divisão([100,2,10]) deve
//    retornar 5. Se a lista for vazia, deve retornar zero.

    /* coloque aqui o seu código */

    if(inteiros.length===0) {
        return 0;
    }

    var resultadoDivisao = inteiros[0];

    for(var i=1; i<inteiros.length; i++) {
        dividendo = inteiros[i];

        if(dividendo==0) {
            throw new Error('Divisão por zero!');
        }

        resultadoDivisao = Math.ceil(resultadoDivisao/dividendo);
    }

    return resultadoDivisao;
}

assert(divisao, [[16, 4, 2]]  , 2 , 'divisao_001');
assert(divisao, [[100, 2, 10]], 5 , 'divisao_002');
assert(divisao, [[]]          , 0 , 'divisao_003');
assert(divisao, [[0]]         , 0 , 'divisao_004');
assert(divisao, [[0, 1]]      , 0 , 'divisao_005');

assertAnyException(divisao, [[1, 0]], 'divisao_006');


function operacao(operador, inteiros) {
//  A função `operacao` deve receber dois parâmetros. O primeiro parâmetro é
//    um caractere indicando a operação aritmética básica a ser realizada ('+',
//    '-', '\*', '/'). O segundo parâmetro é um *array* de números inteiros, para
//    os quais a operação deve ser aplicada. A função deve retornar o resultado
//    da operação no *array*. Chame as funções já criadas para cada operação. Em
//    caso de operação inválida, gere uma exceção.

    /* coloque aqui o seu código */

    switch(operador) {
        case '+': return soma(inteiros);
        case '-': return subtracao(inteiros);
        case '*': return multiplicacao(inteiros);
        case '/': return divisao(inteiros);
        default: throw new Error('Operador inválido');
    }
}

assert(operacao, ['+', [1, 2]],  3 , 'operacao_001');
assert(operacao, ['-', [1, 2]], -1 , 'operacao_002');
assert(operacao, ['*', [1, 2]],  2 , 'operacao_003');
assert(operacao, ['/', [1, 2]],  1 , 'operacao_004');

assertAnyException(operacao, ['=', [1, 2]], 'operacao_005');


function maior(inteiros, quantos) {
//  A função `maior` deve receber um  *array* de números inteiros e retornar
//    qual é o maior deles.

    /* coloque aqui o seu código */

    if(inteiros.length===0) {
        throw new Error('Lista vazia');
    }

    var maiorNumero = inteiros[0];

    for(var i=1; i<inteiros.length; i++) {
        if(inteiros[i]>maiorNumero) {
            maiorNumero = inteiros[i];
        }
    }

    return maiorNumero;
}

assert(maior, [[0, 1, 100]], 100, 'maior_001');
assert(maior, [[0]        ],   0, 'maior_002');

assertAnyException(maior, [[]], 'maior_003');


function intersecao(a, b) {
//  A função `intersecao` deve receber dois *arrays* contendo números
//    inteiros, e retornar a interseção entre os conjuntos, ou seja, um *array*
//    que contenha apenas os números que estejam contidos nos dois *arrays*
//    passados para a função.

    /* coloque aqui o seu código */

    var conjuntoResultante = [];

    for(var i=0; i<a.length; i++) {
        if(b.indexOf(a[i])!=-1) {
            conjuntoResultante.push(a[i]);
        }
    }

    return conjuntoResultante;
}

assert(intersecao, [[], []],         [] , 'intersecao_001');
assert(intersecao, [[1, 2], [3, 4]], [] , 'intersecao_002');
assert(intersecao, [[1, 2], [2, 3]], [2], 'intersecao_003');


print('\nRESULTS:');
print('\tPASS :', pass);
print('\tFAIL :', fail)
print('\tTOTAL:', pass+fail);
print();
print(fail ? 'FAILED TESTS': 'SUCCESS TESTS');
