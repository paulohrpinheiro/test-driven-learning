package main

import (
	"errors"
	"math"
)

var DivisionByZeroError = errors.New("Divisão por zero!")

func Negue(v bool) bool {
	return v
}

func DigaOla(v string) string {
	return ""
}

func ListaNumerosPares(v int) []int {
	return []int{1}
}

func ListaMultiplos(v1 int, v2 int) []int {
	return []int{1, 2, 3, 4, 5}
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
