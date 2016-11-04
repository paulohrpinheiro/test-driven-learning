#ifndef __TDH_PROBLEMS_H__
#define __TDH_PROBLEMS_H__

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


#include <stdbool.h>
#include <setjmp.h>

#include "lists.h"


extern jmp_buf jmp_buffer;


enum {
    OK,
    ERR_DIV_BY_ZERO
};


bool      negue(bool);
char *    diga_ola(const char *);
list_s *  lista_numeros_pares(int);
list_s *  lista_numeros_multiplos(int, int);
int       soma(list_s *);
int       subtracao(list_s *);
int       multiplicacao(list_s *);
int       divisao(list_s *);
int       operacao(char, list_s *);
int       maior(list_s *);
list_s *  intersecao(list_s *, list_s *);

#endif
