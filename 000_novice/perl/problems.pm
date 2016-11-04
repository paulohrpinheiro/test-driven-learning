# Test Driven Learning Project.
# Desenvolva TDD e programação com TDD e programação!
# Módulo novice.
#
# The MIT License (MIT)
#
# Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulohrpinheiro@gmail.com>
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

# Precisa de algum módulo? importe aqui:


# A função `negue` deve receber um valor boleano (verdadeiro ou falso) e
# retornar a negação desse valor.
sub negue {
    not $_[0];
}


# A função `diga_ola` deve ser escrita de tal forma que receba como
# parâmetro um argumento *string*. Deve retornar a *string* "Olá, ", seguida
# do argumento recebido, mais um ponto final. A *string* recebida deve estar
# limpa, ou seja, sem caracteres de espaço no começo ou no fim. Se a *string*
# estiver vazia, retorna apenas "Olá!"
sub diga_ola {
    my $nome = shift;

    # Copiado de http://br.perlmaven.com/trim
    $nome =~ s/^\s+|\s+$//g;

    return "Olá!" if not $nome;
    return "Olá, $nome.";
}


# A função `lista_numeros_pares` deve receber um parâmetro numérico
# inteiro que determina quantos números pares devem estar em um array que
# será o retorno da função.
sub lista_numeros_pares {
    my $quantos = shift;

    map { $_ * 2} (1..$quantos);
}


# A função `lista_multiplos` deve receber dois parâmetros numéricos
# inteiros e retornar uma lista de números inteiros. O tamanho da lista é
# determinado pelo primeiro parâmetro, e o número base será o segundo
# parâmetro.
sub lista_multiplos {
    my $quantos = shift;
    my $base = shift;

    return () if $quantos <1 or $base==0;
    my @lista = map { $_ * $base } (1..$quantos);
    return reverse(@lista) if $base<0;
    return @lista;
}


# A função `soma` deve receber um *array* de números inteiros, e retornar
# a sua soma. Se a lista for vazia, deve retornar zero.
sub soma {
    my @lista = @_;

    return 0 if not @lista;

    my $soma;
    map { $soma += $_ } @lista;

    return $soma;
}


# A função `subtracao` deve receber um *array* de números inteiros, e
# retornar a subtração de todos os elementos em sequência. Por exemplo,
# subtracao([3,2,1]) deve retornar 0, e subtracao([10,2,3]) deve retornar 5.
# Se a lista for vazia, deve retornar zero.
sub subtracao {
    my @lista = @_;

    return 0 if not @lista;

    my $diferenca = $lista[0];
    map { $diferenca -= $_ } @lista[1..(scalar@lista)-1];

    return $diferenca;
}


# """A função `multiplicação` deve receber um *array* de números inteiros, e
# retornar o seu produto. Se a lista for vazia, deve retornar zero.
sub multiplicacao {
    my @lista = @_;

    return 0 if not @lista;

    my $produto = 1;
    map { $produto *= $_ } @lista;

    return $produto;
}


# """A função `divisao` deve receber um *array* de números inteiros, e
# retornar o resultado da sequência de divisões por cada elemento. Por
# exemplo, divisão([16, 4, 2]) deve retornar 2, e divisão([100,2,10]) deve
# retornar 5. Se a lista for vazia, deve retornar zero.
sub divisao {
    my @lista = @_;

    return 0 if not @lista;

    my $resultado = $lista[0];
    {
        use integer;
        map { $resultado /= $_ } @lista[1..(scalar@lista)-1];
    }

    return $resultado;
}


# A função `operacao` deve receber dois parâmetros. O primeiro parâmetro é
# um caractere indicando a operação aritmética básica a ser realizada ('+',
# '-', '\*', '/'). O segundo parâmetro é um *array* de números inteiros, para
# os quais a operação deve ser aplicada. A função deve retornar o resultado
# da operação no *array*. Chame as funções já criadas para cada operação. Em
# caso de operação inválida, gere uma exceção.
sub operacao {
    my ($operador, @lista) = @_;

    return soma(@lista) if $operador eq '+';
    return subtracao(@lista) if $operador eq '-';
    return multiplicacao(@lista) if $operador eq '*';
    return divisao(@lista) if $operador eq '/';
    die("Invalid operator [$operador]");
}


# A função `maior` deve receber um  *array* de números inteiros e retornar
# qual é o maior deles.
sub maior {
    my @lista = @_;

    die("Empty list") if not @lista;
    my @sorted_lista = sort @lista;
    $sorted_lista[-1];
}


# A função `intersecao` deve receber dois *arrays* contendo números
# inteiros, e retornar a interseção entre os conjuntos, ou seja, um *array*
# que contenha apenas os números que estejam contidos nos dois *arrays*
# passados para a função.
sub intersecao {
    my ($lista_a, $lista_b) = @_;

    my %hash_a = map{$_ =>1} @$lista_a;

    my @result = grep($hash_a{$_}, @$lista_b);
    return @result;
}


1;
