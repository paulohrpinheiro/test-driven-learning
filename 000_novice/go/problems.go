package main

import (
	"errors"
	"fmt"
	"math"
	"strings"
)

var DivisionByZeroError = errors.New("Divisão por zero!")
var UnknownOperator = errors.New("Operador desconhecido!")
var EmptySetError = errors.New("Conjunto vazio!")

func Negue(v bool) bool {
	return !v
}

func DigaOla(v string) string {
	if cleaned := strings.TrimSpace(v); cleaned != "" {
		return fmt.Sprintf("Olá, %v.", cleaned)
	}

	return "Olá!"
}

func ListaNumerosPares(quantos int) []int {
	if quantos < 1 {
		return []int{}
	}

	pares := make([]int, quantos)

	for i := range pares {
		pares[i] = (i + 1) * 2
	}

	return pares
}

func ListaMultiplos(quantos int, base int) []int {
	if quantos < 1 || base == 0 {
		return []int{}
	}

	multiplos := make([]int, quantos)

	var factor int
	for i := range multiplos {
		if base < 0 {
			factor = quantos - i
		} else {
			factor = i + 1
		}

		multiplos[i] = base * factor
	}

	return multiplos
}

func Soma(itens []int) int {
	soma := 0

	for _, parcela := range itens {
		soma += parcela
	}

	return soma
}

func Subtracao(itens []int) int {
	if len(itens) == 0 {
		return 0
	}

	resultado := itens[0]

	for _, parcela := range itens[1:] {
		resultado -= parcela
	}

	return resultado
}

func Multiplicacao(itens []int) int {
	if len(itens) == 0 {
		return 0
	}

	resultado := itens[0]

	for _, parcela := range itens[1:] {
		resultado *= parcela
	}

	return resultado
}

func Divisao(itens []int) (int, error) {
	if len(itens) == 0 {
		return 0, nil
	}

	resultado := itens[0]

	for _, parcela := range itens[1:] {
		if parcela == 0 {
			return 0, DivisionByZeroError
		}
		resultado /= parcela
	}

	return resultado, nil
}

func Operacao(o rune, v []int) (int, error) {
	return math.MaxInt8, nil
}

func Maior(v []int) (int, error) {
	return math.MaxInt8, nil
}

func Intersecao(s1 []int, s2 []int) []int {
	return []int{0, 0, 0, 0}
}
