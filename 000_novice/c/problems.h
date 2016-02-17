#ifndef __TDH_PROBLEMS_H__
#define __TDH_PROBLEMS_H__

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


#include <stdbool.h>


typedef struct {
    int *array;
    int elements;
} list_s;


bool      negue(bool valor);
wchar_t * diga_ola(const wchar_t *nome);
list_s *  lista_numeros_pares(int quantos);
list_s *  lista_multiplos(int quantos, int base);
int       soma(list_s *lista);
int       subtracao(list_s *lista);
int       multiplicacao(list_s *lista);
int       divisao(list_s *lista);
int       operacao(char operador, list_s *lista);
int       maior(list_s *lista);
list_s *  intersecao(list_s *a, list_s *b);

#endif
