# Test Driven Learning Project.
# Desenvolva TDD e programação com TDD e programação!
# Módulo novice.
#
# The MIT License (MIT)
#
# Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulo@sysincloud.it>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


use strict;
use warnings;

use Test::Simple tests => 47;

use solved;


ok( negue(0), "negue: False" );
ok( (not negue(1)) , "negue: True" );

ok( diga_ola("") eq "Olá!", "diga_ola('')");
ok( diga_ola("Paulo") eq "Olá, Paulo.", "diga_ola('Paulo')");
ok( diga_ola("  Paulo  ") eq "Olá, Paulo.", "diga_ola('  Paulo  ')");
ok( diga_ola("  Paulo Henrique ") eq "Olá, Paulo Henrique.", "diga_ola('  Paulo  ')");

ok( join('.', lista_numeros_pares( 0)) eq "", "lista_pares(0)" );
ok( join('.', lista_numeros_pares( 1)) eq "2", "lista_pares(1)" );
ok( join('.', lista_numeros_pares( 4)) eq "2.4.6.8", "lista_pares(4)" );
ok( join('.', lista_numeros_pares( 5)) eq "2.4.6.8.10", "lista_pares(5)" );
ok( join('.', lista_numeros_pares(-1)) eq "", "lista_pares(-1)" );

ok( join('.', lista_multiplos( 0, 10)) eq "", "lista_multiplos( 0, 10)" );
ok( join('.', lista_multiplos(-1, 10)) eq "", "lista_multiplos(-1, 10)" );
ok( join('.', lista_multiplos( 3, -1)) eq "-3.-2.-1", "lista_multiplos(3, -1)" );
ok( join('.', lista_multiplos( 3,  0)) eq "", "lista_multiplos(3, 0)" );
ok( join('.', lista_multiplos( 3, 10)) eq "10.20.30", "lista_multiplos(3, 10)" );

ok( soma(()) == 0, "soma(())" );
ok( soma((1,)) == 1, "soma((1,))" );
ok( soma((1, 2)) == 3, "soma((1, 2))" );

ok( subtracao((3, 2, 1)) == 0, "subtracao((3, 2, 1))" );
ok( subtracao((10, 2, 3)) == 5, "subtracao((10, 2, 3))" );
ok( subtracao(()) == 0, "subtracao(())" );
ok( subtracao((1, 2)) == -1, "subtracao((1, 2))" );
ok( subtracao((-1, -2, -3)) == 4, "subtracao((-1, -2, -3))" );
ok( subtracao((9, 3 ,2 ,1)) == 3, "subtracao((9, 3 ,2 ,1)))" );

ok( multiplicacao((1, 2, 3)) == 6, "multiplicacao((1, 2, 3))" );
ok( multiplicacao(()) == 0 , "multiplicacao(()" );
ok( multiplicacao((-2, 1, 4)) == -8, "multiplicacao((-2, 1, 4))" );
ok( multiplicacao((-2, -1, 4)) == 8 , "multiplicacao((-2, -1, 4))" );

ok( divisao((5, 2)) == 2, "divisao((5, 2))" );
ok( divisao(()) == 0, "divisao(())" );
ok( divisao((0)) == 0, "divisao((0))" );
ok( divisao((16, 4, 2)) == 2, "divisao((16, 4, 2))" );
ok( divisao((100, 2, 10)) == 5, "divisao((100, 2, 10))" );
ok( divisao((0, 1)) == 0, "divisao((0, 1))" );
eval { divisao((1, 0)) };
ok( $@ =~ /^Illegal division by zero at/, "divisao((1, 0))" );

ok( operacao('+', (1, 2)) ==  3 , "operacao('+', (1, 2))" );
ok( operacao('-', (1, 2)) == -1 , "operacao('-', (1, 2))" );
ok( operacao('*', (1, 2)) ==  2 , "operacao('*', (1, 2))" );
ok( operacao('/', (1, 2)) ==  0 , "operacao('/', (1, 2))" );
eval { operacao(' ', (1, 2)) };
ok( $@ =~ /^Invalid operator \[ \]/, "operacao(' ', (1, 2))" );

ok( maior((0, 1, 100)) == 100, "maior((0, 1, 100))" );
ok( maior((0)) == 0, "maior((0))" );
eval { maior(()) };
ok( $@ =~ /^Empty list/, "maior(())" );

my @arr0 = ();
my @arr1 = (1, 2);
my @arr2 = (2, 3);
my @arr3 = (3, 4);

ok( join('.', intersecao(\@arr0, \@arr0)) eq "", "intersecao((), ())" );
ok( join('.', intersecao(\@arr1, \@arr3)) eq "", "intersecao((1, 2), (3, 4))" );
ok( join('.', intersecao(\@arr1, \@arr2)) eq "2", "intersecao((1, 2), (2, 3))" );
