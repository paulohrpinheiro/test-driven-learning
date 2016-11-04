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


require 'test/unit'

require_relative 'solved'

class TestProblems < Test::Unit::TestCase

    def test_negue
        assert_equal(true, TestDrivenLearning.negue(false))
        assert_equal(true, (not TestDrivenLearning.negue(true)))
    end

    def test_diga_ola
        assert_equal('Olá!', TestDrivenLearning.diga_ola(''))
        assert_equal('Olá, Paulo.', TestDrivenLearning.diga_ola('Paulo'))
        assert_equal('Olá, Paulo.', TestDrivenLearning.diga_ola('  Paulo  '))
        assert_equal('Olá, Paulo Henrique.', TestDrivenLearning.diga_ola('  Paulo Henrique '))
    end

    def test_lista_numeros_pares
        assert_equal([], TestDrivenLearning.lista_numeros_pares(0))
        assert_equal([2], TestDrivenLearning.lista_numeros_pares(1))
        assert_equal([2,4,6,8], TestDrivenLearning.lista_numeros_pares(4))
        assert_equal([], TestDrivenLearning.lista_numeros_pares(-1))
    end

    def test_lista_multiplos
        assert_equal([], TestDrivenLearning.lista_multiplos(0, 10))
        assert_equal([], TestDrivenLearning.lista_multiplos(-1, 10))
        assert_equal([-3,-2,-1], TestDrivenLearning.lista_multiplos(3, -1))
        assert_equal([], TestDrivenLearning.lista_multiplos(3, 0))
        assert_equal([10,20,30], TestDrivenLearning.lista_multiplos(3, 10))
    end

    def test_soma
        assert_equal(0, TestDrivenLearning.soma([]))
        assert_equal(1, TestDrivenLearning.soma([1]))
        assert_equal(3, TestDrivenLearning.soma([1,2]))
    end

    def test_subtracao
        assert_equal(0, TestDrivenLearning.subtracao([3,2,1]))
        assert_equal(5, TestDrivenLearning.subtracao([10,2,3]))
        assert_equal(0, TestDrivenLearning.subtracao([]))
        assert_equal(-1, TestDrivenLearning.subtracao([1,2]))
        assert_equal(4, TestDrivenLearning.subtracao([-1,-2,-3]))
        assert_equal(3, TestDrivenLearning.subtracao([9,3,2,1]))
    end

    def test_multiplicacao
        assert_equal(6, TestDrivenLearning.multiplicacao([1,2,3]))
        assert_equal(0, TestDrivenLearning.multiplicacao([]))
        assert_equal(-8, TestDrivenLearning.multiplicacao([-2,1,4]))
        assert_equal(8, TestDrivenLearning.multiplicacao([-2,-1,4]))
    end

    def test_divisao
        assert_equal(2, TestDrivenLearning.divisao([5,2]))
        assert_equal(0, TestDrivenLearning.divisao([]))
        assert_equal(0, TestDrivenLearning.divisao([0]))
        assert_equal(2, TestDrivenLearning.divisao([16,4,2]))
        assert_equal(5, TestDrivenLearning.divisao([100,2,10]))
        assert_equal(0, TestDrivenLearning.divisao([0,1]))
        assert_raise(ZeroDivisionError){TestDrivenLearning.divisao([1,0])}
    end

    def test_operacao
        assert_equal(3, TestDrivenLearning.operacao('+', [1,2]))
        assert_equal(-1, TestDrivenLearning.operacao('-', [1,2]))
        assert_equal(2, TestDrivenLearning.operacao('*', [1,2]))
        assert_equal(0, TestDrivenLearning.operacao('/', [1,2]))
        assert_raise(RuntimeError){TestDrivenLearning.operacao(' ', [1,2])}
    end

    def test_maior
        assert_equal(100, TestDrivenLearning.maior([0,1,100]))
        assert_equal(0, TestDrivenLearning.maior([0]))
        assert_raise(RuntimeError){TestDrivenLearning.maior([])}
    end

    def test_intersecao
        arr0 = []
        arr1 = [1,2]
        arr2 = [2,3]
        arr3 = [3,4]

        assert_equal([], TestDrivenLearning.intersecao(arr0, arr0))
        assert_equal([], TestDrivenLearning.intersecao(arr1, arr3))
        assert_equal([2], TestDrivenLearning.intersecao(arr1, arr2))
    end

end
