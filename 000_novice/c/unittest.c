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


#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "minunit.h"
#include "lists.h"

#include "problems.h"


int tests_run = 0;

void free_heap(void *ptr) {
    if(NULL != (void *)ptr) {
        free(ptr);
    }

    ptr = NULL;
}

static char *test_negue() {
    mu_assert("FAIL negue(true).", false == negue(true));
    mu_assert("FAIL negue(false).", true  == negue(false));

    return 0;
}

bool compara_diga_ola(const char *nome, const char *esperado) {
    char *retornado;
    bool deu_certo;

    retornado = diga_ola(nome);
    assert(NULL!=retornado);

    deu_certo = (0 == strcmp(esperado, retornado));

    free_heap(retornado);
    return deu_certo;
}

static char *test_diga_ola(void) {
    mu_assert("Error in test_diga_ola('').",          compara_diga_ola("", "Olá!"));
    mu_assert("Error in test_diga_ola('Paulo').",     compara_diga_ola("Paulo", "Olá, Paulo."));
    mu_assert("Error in test_diga_ola('  Paulo  ').", compara_diga_ola("  Paulo  ", "Olá, Paulo."));

    return 0;
}

static char *test_lista_numeros_pares(void) {
    list_s result_for_1, result_for_4, result_for_5;
    int list_for_1[] = {2};
    int list_for_4[] = {2, 4, 6, 8};
    int list_for_5[] = {2, 4, 6, 8, 10};

    result_for_1.array = &list_for_1[0];
    result_for_1.elements = 1;
    assert(result_for_1.elements == sizeof(result_for_1.array)/sizeof(int));

    result_for_4.array = &list_for_4[0];
    result_for_4.elements = 4;
    assert(result_for_4.elements == sizeof(result_for_4.array)/sizeof(int));

    result_for_5.array = &list_for_5[0];
    result_for_5.elements = 5;
    assert(result_for_5.elements == sizeof(result_for_5.array)/sizeof(int));

    mu_assert("Error in  0.", is_equal_list(lista_numeros_pares(0),  NULL));
    mu_assert("Error in  1.", is_equal_list(lista_numeros_pares(1),  &result_for_1));
    mu_assert("Error in  4.", is_equal_list(lista_numeros_pares(4),  &result_for_4));
    mu_assert("Error in  5.", is_equal_list(lista_numeros_pares(5),  &result_for_5));
    mu_assert("Error in -1.", is_equal_list(lista_numeros_pares(-1), NULL));

    return 0;
}

static char *test_lista_numeros_multiplos(void) {

    return 0;
}


static char *test_soma(void) {

    return 0;
}


static char *test_subtracao(void) {

    return 0;
}


static char *test_multiplicacao(void) {

    return 0;
}


static char *test_divisao(void) {

    return 0;
}


static char *test_operacao(void) {

    return 0;
}


static char *test_maior(void) {

    return 0;
}


static char *test_intersecao(void) {


    return 0;
}


static char *all_tests(void) {
    mu_run_test(test_negue);
    mu_run_test(test_diga_ola);
    mu_run_test(test_lista_numeros_pares);
    mu_run_test(test_lista_numeros_multiplos);
    mu_run_test(test_soma);
    mu_run_test(test_subtracao);
    mu_run_test(test_multiplicacao);
    mu_run_test(test_divisao);
    mu_run_test(test_operacao);
    mu_run_test(test_maior);
    mu_run_test(test_intersecao);

    return 0;
}


int main(void) {
    char *result = all_tests();

    printf("Tests run: %d\n", tests_run);

    if(0!=result) {
        puts(result);
        return EXIT_FAILURE;
    }

    puts("ALL TESTS PASSED!");
    return EXIT_SUCCESS;
}
