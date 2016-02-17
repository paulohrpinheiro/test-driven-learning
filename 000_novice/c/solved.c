/*
Test Driven Learning Project.
Desenvolva TDD e programação com TDD e programação!
Módulo novice.

The MIT License (MIT)

Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulo@sysincloud.it>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "problems.h"

/* Precisa dar um include para alguma biblioteca ou extensão? inclua aqui. */



bool negue(bool valor) {
/*  A função `negue` deve receber um valor boleano (verdadeiro ou falso) e
    retornar a negação desse valor.

    negue(frue)  -> false
    negue(False) -> true
*/

    /* coloque aqui o seu código */
    if(true==valor) {
        return false;
    } else {
        return true;
    }
}

char *clean_str(const char *polluted_str) {
    char *begin, *end, *clean_str;
    size_t len;

    begin = (char *)polluted_str;
    end = (char *)polluted_str + strlen(polluted_str) -1;

    while('\0'!=*begin && isspace(*begin)) {
        begin++;
    }

    while(begin!=end && isspace(*end)) {
        end--;
    }

    len = end - begin + 1;

    clean_str = (char *)calloc(len, sizeof(char));

    if(NULL==clean_str) {
        return NULL;
    }

    return strncpy(clean_str, begin, len);
}


char *diga_ola(const char *nome) {
/*  A função `diga_ola` deve ser escrita de tal forma que receba como
    parâmetro um argumento *string*. Deve retornar a *string* "Olá, ", seguida
    do argumento recebido, mais um ponto final. A *string* recebida deve estar
    limpa, ou seja, sem caracteres de espaço no começo ou no fim. Se a *string*
    estiver vazia, retorna apenas "Olá!"

    diga_ola("")          -> "Olá!"
    diga_ola("    ")      -> "Olá!"
    diga_ola("Paulo")     -> "Olá, Paulo."
    diga_ola("  Paulo  ") -> "Olá, Paulo."
*/

    /* coloque aqui o seu código */
    char *sem_espacos, *masc, *gretting;

    char *empty = "Olá!";
    char *no_empty = "Olá, %s.";

    sem_espacos = clean_str(nome);

    if(NULL==sem_espacos) {
        return NULL;
    }

    if(0==strlen(sem_espacos)) {
        masc = empty;
    }
    else {
        masc = no_empty;
    }

    gretting = (char *)calloc(strlen(masc)+strlen(sem_espacos)+1, sizeof(char));

    if(NULL==gretting) {
        free(sem_espacos);
        return NULL;
    }

    sprintf(gretting, masc, sem_espacos);

    return gretting;
}


list_s *lista_numeros_pares(int elements) {
/*  A função `lista_numeros_pares` deve receber um parâmetro numérico
    inteiro que determina quantos números pares devem estar em um array que
    será o retorno da função.

    lista_numeros_pares(0)  -> NULL
    lista_numeros_pares(1)  -> {2}
    lista_numeros_pares(4)  -> {2, 4, 6, 8}
    lista_numeros_pares(5)  -> {2, 4, 6, 8, 10}
    lista_numeros_pares(-1) -> NULL
*/

    /* coloque aqui o seu código */
    list_s *list;

    if(elements<1) {
        return NULL;
    }

    list = new_list(elements);

    if(NULL==list) {
        return NULL;
    }

    {
        int i;

        for(i=0; i<elements; i++) {
            list->array[i] = (i+1)*2;
        }
    }

    return list;
}


list_s *lista_numeros_multiplos(int elements, int base) {
/*  A função `lista_multiplos` deve receber dois parâmetros numéricos
    inteiros e retornar uma lista de números inteiros. O tamanho da lista é
    determinado pelo primeiro parâmetro, e o número base será o segundo
    parâmetro.

    lista_multiplos(0, 10)  -> NULL
    lista_multiplos(-1, 10) -> NULL
    lista_multiplos(3, -1)  -> {-3, -2, -1}
    lista_multiplos(3, 0)   -> NULL
    lista_multiplos(3, 10)  -> {10, 20, 30}
*/

    /* coloque aqui o seu código */
    list_s *list;

    if(elements<1) {
        return NULL;
    }

    list = new_list(elements);

    if(NULL==list) {
        return NULL;
    }

    {
        int i;

        if(base>0) {
            for(i=0; i<elements; i++) {
                list->array[i] = (i+1)*base;
            }
        } else {
            for(i=elements; i>0; i--) {
                list->array[elements-i] = i*base;
            }
        }
    }

    return list;
}


int soma(list_s *lista) {
/*  A função `soma` deve receber um *array* de números inteiros, e retornar
    a sua soma. Se a lista for vazia, deve retornar zero.

    { int *i = {};     soma(i, 0); } -> 0
    { int *i = {1};    soma(i, 1); } -> 1
    { int *i = {1, 2}; soma(i, 2); } -> 3
*/

    /* coloque aqui o seu código */
    return 0;

}


int subtracao(list_s *soma) {
/*  A função `subtracao` deve receber um *array* de números inteiros, e
    retornar a subtração de todos os elementos em sequência. Por exemplo,
    subtracao([3,2,1]) deve retornar 0, e subtracao([10,2,3]) deve retornar 5.
    Se a lista for vazia, deve retornar zero.

    { int *i = {3, 2, 1};    subtracao(i, 3); } ->  0
    { int *i = {10, 2, 3};   subtracao(i, 3); } ->  5
    { int *i = {};           subtracao(i, 0); } ->  0
    { int *i = {1, 2};       subtracao(i, 2); } -> -1
    { int *i = {-1, -2, -3}; subtracao(i, 3); } ->  4
*/

    /* coloque aqui o seu código */
    return 0;

}


int multiplicacao(list_s *soma) {
/*  A função `multiplicação` deve receber um *array* de números inteiros, e
    retornar o seu produto. Se a lista for vazia, deve retornar zero.

    { int *i = {1, 2, 3};    multiplicacao(i, 3); } ->  6
    { int *i = {};           multiplicacao(i, 0); } ->  0
    { int *i = {-2, 1, 4};   multiplicacao(i, 3); } -> -8
    { int *i = {-2, -1, -4}; multiplicacao(i, 3); } ->  8
*/

    /* coloque aqui o seu código */
    return 0;

}


int divisao(list_s *soma) {
/*   A função `divisao` deve receber um *array* de números inteiros, e
    retornar o resultado da sequência de divisões por cada elemento. Por
    exemplo, divisão([16, 4, 2]) deve retornar 2, e divisão([100,2,10]) deve
    retornar 5. Se a lista for vazia, deve retornar zero.

    { int *i = {};     divisao(i, 0); } -> 0
    { int *i = {0};    divisao(i, 1); } -> 0
    { int *i = {0, 1}; divisao(i, 2); } -> 0
    { int *i = {1, 0}; divisao(i, 2); } -> deve dar pânico
*/

    /* coloque aqui o seu código */
    return 0;

}


int operacao(char operador, list_s *soma) {
/*  A função `operacao` deve receber dois parâmetros. O primeiro parâmetro é
    um caractere indicando a operação aritmética básica a ser realizada ('+',
    '-', '\*', '/'). O segundo parâmetro é um *array* de números inteiros, para
    os quais a operação deve ser aplicada. A função deve retornar o resultado
    da operação no *array*. Chame as funções já criadas para cada operação. Em
    caso de operação inválida, gere uma exceção.

    { int *i = {1, 2}; operacao('+', i, 2); } -> 3
    { int *i = {1, 2}; operacao('-', i, 2); } -> 1
    { int *i = {1, 2}; operacao('*', i, 2); } -> 2
    { int *i = {1, 2}; operacao('/', i, 2); } -> 0
    { int *i = {1, 2}; operacao('=', i, 2); } -> deve dar pânico
*/

    /* coloque aqui o seu código */
    return 0;

}


int maior(list_s *soma) {
/*  A função `maior` deve receber um  *array* de números inteiros e retornar
    qual é o maior deles.

    { int *i = {0, 1, 100}; maior(i, 3); } -> 100
    { int *i = {0};         maior(i, 1); } ->   0
    { int *i = {};          maior(i, 0); } -> deve dar pânico
*/

    /* coloque aqui o seu código */
    return 0;

}


list_s *intersecao(list_s *a, list_s *b) {
/*  A função `intersecao` deve receber dois *arrays* contendo números
    inteiros, e retornar a interseção entre os conjuntos, ou seja, um *array*
    que contenha apenas os números que estejam contidos nos dois *arrays*
    passados para a função.

    { int *a = {}, b = {};         intersecao(a, 0, b, 0); } -> NULL
    { int *a = {1, 2}, b = {3, 4}; intersecao(a, 2, b, 2); } -> NULL
    { int *a = {1, 2}, b = {2, 3}; intersecao(a, 2, b, 2); } -> {2}
*/

    /* coloque aqui o seu código */
    return NULL;

}
