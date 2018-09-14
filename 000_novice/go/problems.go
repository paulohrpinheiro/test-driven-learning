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

	response := make([]int, quantos)

	for i := range response {
		response[i] = (i + 1) * 2
	}

	return response
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

func Soma(v []int) int {
	return math.MaxInt8
}

func Subtracao(v []int) int {
	return math.MaxInt8
}

func Multiplicacao(v []int) int {
	return math.MaxInt8
}

func Divisao(v []int) (int, error) {
	return math.MaxInt8, nil
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
