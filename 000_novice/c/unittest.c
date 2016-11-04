/*
Test Driven Learning Project.
Desenvolva TDD e programação com TDD e programação!
Módulo novice.

The MIT License (MIT)

Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulohrpinheiro@gmail.com>

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
#include <setjmp.h>

#include "minunit.h"
#include "lists.h"

#include "problems.h"


int tests_run = 0;
jmp_buf jmp_buffer;

void free_heap(void *ptr) {
    if(NULL != (void *)ptr) {
        free(ptr);
    }

    ptr = NULL;
}

static char *test_negue() {
    puts("=> test_negue:");
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
    puts("=> test_diga_ola:");
    mu_assert("Error in test_diga_ola('').",          compara_diga_ola("", "Olá!"));
    mu_assert("Error in test_diga_ola('Paulo').",     compara_diga_ola("Paulo", "Olá, Paulo."));
    mu_assert("Error in test_diga_ola('  Paulo  ').", compara_diga_ola("  Paulo  ", "Olá, Paulo."));

    return 0;
}

static char *test_lista_numeros_pares(void) {
    list_s *result, result_for_1, result_for_4, result_for_5;
    int list_for_1[] = {2};
    int list_for_4[] = {2, 4, 6, 8};
    int list_for_5[] = {2, 4, 6, 8, 10};

    result_for_1.array = list_for_1;
    result_for_1.elements = 1;

    result_for_4.array = list_for_4;
    result_for_4.elements = 4;

    result_for_5.array = list_for_5;
    result_for_5.elements = 5;

    puts("=> test_lista_numeros_pares:");

    result = lista_numeros_pares(0);
    mu_assert("Error in  0.", is_equal_list(result,  NULL));
    free_list(result);

    result = lista_numeros_pares(1);
    mu_assert("Error in  1.", is_equal_list(result,  &result_for_1));
    free_list(result);

    result = lista_numeros_pares(4);
    mu_assert("Error in  4.", is_equal_list(result,  &result_for_4));
    free_list(result);

    result = lista_numeros_pares(5);
    mu_assert("Error in  5.", is_equal_list(result,  &result_for_5));
    free_list(result);

    result = lista_numeros_pares(-1);
    mu_assert("Error in -1.", is_equal_list(result, NULL));
    free_list(result);

    return 0;
}

static char *test_lista_numeros_multiplos(void) {
    list_s *result, result_for_1neg, result_for_10pos;
    int list_for_1neg[] = {-3, -2, -1};
    int list_for_10pos[] = {10, 20, 30};

    result_for_1neg.array = list_for_1neg;
    result_for_1neg.elements = 3;

    result_for_10pos.array = list_for_10pos;
    result_for_10pos.elements = 3;

    puts("=> test_lista_numeros_multiplos:");

    result = lista_numeros_multiplos(0, 10);
    mu_assert("Error in  (0, 10).", is_equal_list(result,  NULL));
    free_list(result);

    result = lista_numeros_multiplos(-1, 10);
    mu_assert("Error in  (-1, 10).", is_equal_list(result,  NULL));
    free_list(result);

    result = lista_numeros_multiplos(3, -1);
    mu_assert("Error in  (3, -1).", is_equal_list(result,  &result_for_1neg));
    free_list(result);

    result = lista_numeros_multiplos(3, 0);
    mu_assert("Error in  (3, 0).", is_equal_list(result,  NULL));
    free_list(result);

    result = lista_numeros_multiplos(3, 10);
    mu_assert("Error in  (3, 10).", is_equal_list(result,  &result_for_10pos));
    free_list(result);

    return 0;
}


static char *test_soma(void) {
    list_s *list_with_0, list_with_1, list_with_2;
    int list_for_1[] = {1};
    int list_for_2[] = {1, 2};

    list_with_1.array = list_for_1;
    list_with_1.elements = 1;

    list_with_2.array = list_for_2;
    list_with_2.elements = 2;

    puts("=> test_soma:");

    mu_assert("Error in  NULL.", 0 == soma(NULL));
    list_with_0 = new_list(0);
    mu_assert("Error in 0 (create).", NULL!=list_with_0);
    mu_assert("Error in 0.", 0==soma(list_with_0));
    free_list(list_with_0);

    mu_assert("Error in  1.", 1==soma(&list_with_1));
    mu_assert("Error in  2.", 3==soma(&list_with_2));

    return 0;
}


static char *test_subtracao(void) {
    list_s list1, list2, list4, list5;
    list_s *list3;
    int l1[] = {3, 2, 1};
    int l2[] = {10, 2, 3};
    int l4[] = {1, 2};
    int l5[] = {-1, -2, -3};

    list1.array = l1;
    list1.elements = 3;

    list2.array = l2;
    list2.elements = 3;

    list4.array = l4;
    list4.elements = 2;

    list5.array = l5;
    list5.elements = 3;

    puts("=> test_subtracao:");

    mu_assert("Error in  list1.", 0==subtracao(&list1));
    mu_assert("Error in  list2.", 5==subtracao(&list2));

    mu_assert("Error in  NULL.", 0 == subtracao(NULL));
    list3 = new_list(0);
    mu_assert("Error in 0 (create).", NULL!=list3);
    mu_assert("Error in 0.", 0==subtracao(list3));
    free_list(list3);

    mu_assert("Error in  4.", -1==subtracao(&list4));
    mu_assert("Error in  5.",  4==subtracao(&list5));

    return 0;
}


static char *test_multiplicacao(void) {
    list_s list1, list3, list4;
    list_s *list2;
    int l1[] = {1, 2, 3};
    int l3[] = {-2, 1, 4};
    int l4[] = {-2, -1, 4};

    list1.array = l1;
    list1.elements = 3;

    list3.array = l3;
    list3.elements = 3;

    list4.array = l4;
    list4.elements = 3;

    puts("=> test_multiplicacao:");

    mu_assert("Error in list1.", 6==multiplicacao(&list1));

    mu_assert("Error in NULL.", 0 == multiplicacao(NULL));
    list2 = new_list(0);
    mu_assert("Error in list2 (create).", NULL!=list2);
    mu_assert("Error in list2.", 0==multiplicacao(list2));
    free_list(list2);

    mu_assert("Error in  list3.", -8==multiplicacao(&list3));
    mu_assert("Error in  list4.",  8==multiplicacao(&list4));

    return 0;
}


void div_by_zero(int signum) {
    puts("div by zero catched...");
}

static char *test_divisao(void) {
    list_s list1, list3, list4, list5, list6, list7;
    list_s *list2;
    int l1[] = {5, 2};
    int l3[] = {0};
    int l4[] = {16, 4, 2};
    int l5[] = {100, 2, 10};
    int l6[] = {0, 1};
    int l7[] = {1, 0};

    list1.array = l1;
    list1.elements = 2;

    list3.array = l3;
    list3.elements = 1;

    list4.array = l4;
    list4.elements = 3;

    list5.array = l5;
    list5.elements = 3;

    list6.array = l6;
    list6.elements = 2;

    list7.array = l7;
    list7.elements = 2;

    puts("=> test_divisao:");

    mu_assert("Error in list1.", 2==divisao(&list1));

    mu_assert("Error in NULL.", 0 == divisao(NULL));
    list2 = new_list(0);
    mu_assert("Error in list2 (create).", NULL!=list2);
    mu_assert("Error in list2.", 0==divisao(list2));
    free_list(list2);

    mu_assert("Error in list3.", 0==divisao(&list3));
    mu_assert("Error in list4.", 2==divisao(&list4));
    mu_assert("Error in list5.", 5==divisao(&list5));
    mu_assert("Error in list6.", 0==divisao(&list6));

    {
        int err_code;

        err_code = setjmp(jmp_buffer);

        if(OK==err_code) {
            divisao(&list7);
            mu_assert("Error in list7 false.", false);
        }
        else {
            mu_assert("Error in list7.", ERR_DIV_BY_ZERO==err_code);
        }
    }

    return 0;
}


static char *test_operacao(void) {
    list_s list;
    int array[] = {1, 2};

    list.array = array;
    list.elements = 2;

    puts("=> test_operacao:");

    mu_assert("Error in '+'.",  3 == operacao('+', &list));
    mu_assert("Error in '-'.", -1 == operacao('-', &list));
    mu_assert("Error in '*'.",  2 == operacao('*', &list));
    mu_assert("Error in '/'.",  0 == operacao('/', &list));

    return 0;
}

static char *test_maior(void) {
    list_s list1, list2;
    int l1[] = {0, 1, 100};
    int l2[] = {0};

    list1.array = l1;
    list1.elements = 3;

    list2.array = l2;
    list2.elements = 1;

    puts("=> test_maior:");

    mu_assert("Error in list1.", 100==maior(&list1));
    mu_assert("Error in list2.",   0==maior(&list2));

    return 0;
}


static char *test_intersecao(void) {
    list_s *result, list12, list34, list23, listr;
    int l12[] = {1, 2};
    int l34[] = {3, 4};
    int l23[] = {2, 3};
    int lr[] = {2};

    list12.array = l12;
    list12.elements = 2;

    list34.array = l34;
    list34.elements = 2;

    list23.array = l23;
    list23.elements = 2;

    listr.array = lr;
    listr.elements = 1;

    puts("=> test_intersecao:");

    result = intersecao(&list12, &list34);
    mu_assert("Error in list12xlist34.", is_equal_list(result, NULL));
    free_list(result);

    result = intersecao(&list12, &list23);
    mu_assert("Error in list12xlist23.", is_equal_list(result, &listr));
    free_list(result);

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
