#ifndef __PROBLEMS_H__
#define __PROBLEMS_H__

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

bool      negue(bool valor);
wchar_t * diga_ola(const wchar_t *nome);
int *     lista_numeros_pares(int quantos);
int *     lista_multiplos(int quantos, int base);
int       soma(int *inteiros, size_t quantos);
int       subtracao(int *inteiros, size_t quantos);
int       multiplicacao(int *inteiros, size_t quantos);
int       divisao(int *inteiros, size_t quantos);
int       operacao(char operador, int *inteiros, size_t quantos);
int       maior(int *inteiros, size_t quantos);
int *     intersecao(int *a, size_t a_size, int *b, size_t b_size);

#endif
