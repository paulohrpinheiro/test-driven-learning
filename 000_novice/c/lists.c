#ifndef __LISTS_H__
#define __LISTS_H__

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
#include <stdbool.h>

#include "lists.h"


list_s *new_list(int elements) {
    list_s *list;

    list = (list_s *)malloc(sizeof(list_s));

    if(NULL==list) {
        return NULL;
    }

    list->array = (int *)calloc(elements, sizeof(int));

    if(NULL==list->array) {
        free_list(list);
        return NULL;
    }

    return list;
}


bool is_equal_list(list_s *a, list_s *b) {
    int i;

    if(NULL==a->array || NULL==b->array || a->elements!=b->elements) {
        return false;
    }

    for(i=1; i<a->elements; i++) {
        if(a->array[i] != b->array[i]) {
            return false;
        }
    }

    return true;
}


void free_list(list_s *list) {
    if(NULL==list) {
        return;
    }

    if(NULL!=list->array) {
        free(list->array);
        list->array = NULL;
    }

    free(list);
    list = NULL;
}


#endif
