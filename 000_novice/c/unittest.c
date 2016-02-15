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


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "minunit.h"
#include "problems.h"


int tests_run = 0;

void free_heap(void *ptr) {
    if(NULL != (void *)ptr) {
        free(ptr);
    }

    ptr = NULL;
}

bool array_is_equal(int *a, int *b) {
    int i;

    if(NULL==a && NULL==b) {
        return true;
    }

    if(NULL==a || NULL==b || a[0] != b[0]) {
        return false;
    }

    for(i=1; i<=a[0]; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

static char *test_negue() {
    mu_assert("FAIL negue(true).", false == negue(true));
    mu_assert("FAIL negue(false).", true  == negue(false));

    return 0;
}

bool compara_diga_ola(const wchar_t *nome, const wchar_t *esperado) {
    wchar_t *retornado;
    bool deu_certo;

    retornado = diga_ola(nome);
    assert(NULL!=retornado);
    deu_certo = (0 == wcscmp(esperado, retornado));

    free_heap(retornado);
    return deu_certo;
}

static char *test_diga_ola(void) {
    mu_assert("Error in test_diga_ola('').",          compara_diga_ola(L"", L"Olá!"));
    mu_assert("Error in test_diga_ola('Paulo').",     compara_diga_ola(L"Paulo", L"Olá, Paulo."));
    mu_assert("Error in test_diga_ola('  Paulo  ').", compara_diga_ola(L"  Paulo  ", L"Olá, Paulo."));

    return 0;
}

static char *test_lista_numeros_pares(void) {
    int result_for_1[] = {1, 2};
    int result_for_4[] = {4, 2, 4, 6, 8};
    int result_for_5[] = {5, 2, 4, 6, 8, 10};

    mu_assert("Error in  0.", array_is_equal(lista_numeros_pares(0),  NULL));
    mu_assert("Error in  1.", array_is_equal(lista_numeros_pares(1),  result_for_1));
    mu_assert("Error in  4.", array_is_equal(lista_numeros_pares(4),  result_for_4));
    mu_assert("Error in  5.", array_is_equal(lista_numeros_pares(5),  result_for_5));
    mu_assert("Error in -1.", array_is_equal(lista_numeros_pares(-1), NULL));

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
