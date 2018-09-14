package main

import (
	"reflect"
	"testing"
)

func TestNegue(t *testing.T) {
	var tests = []struct {
		input bool
		want  bool
	}{
		{true, false},
		{false, true},
	}

	for _, test := range tests {
		if got := Negue(test.input); got != test.want {
			t.Errorf("Negue(%t) = %t", test.input, got)
		}
	}
}

func TestDigaOla(t *testing.T) {
	var tests = []struct {
		input string
		want  string
	}{
		{"", "Olá!"},
		{"    ", "Olá!"},
		{"Paulo", "Olá, Paulo."},
		{"  Paulo  ", "Olá, Paulo."},
	}

	for _, test := range tests {
		if got := DigaOla(test.input); got != test.want {
			t.Errorf("DigaOla(%q) = %q", test.input, got)
		}
	}
}

func TestListaNumerosPares(t *testing.T) {
	var tests = []struct {
		input int
		want  []int
	}{
		{0, []int{}},
		{1, []int{2}},
		{4, []int{2, 4, 6, 8}},
		{5, []int{2, 4, 6, 8, 10}},
		{-1, []int{}},
	}

	for _, test := range tests {
		got := ListaNumerosPares(test.input)

		if !reflect.DeepEqual(got, test.want) {
			t.Errorf("ListaNumerosPares(%v) = %v", test.input, got)
		}
	}
}

func TestListaMultiplos(t *testing.T) {
	var tests = []struct {
		input1 int
		input2 int
		want   []int
	}{
		{0, 10, []int{}},
		{-1, 10, []int{}},
		{3, -1, []int{-3, -2, -1}},
		{3, 0, []int{}},
		{3, 10, []int{10, 20, 30}},
	}

	for _, test := range tests {
		got := ListaMultiplos(test.input1, test.input2)

		if !reflect.DeepEqual(got, test.want) {
			t.Errorf("ListaMultiplos(%v, %v) = %v", test.input1, test.input2, got)
		}
	}
}

func TestSoma(t *testing.T) {
	var tests = []struct {
		input []int
		want  int
	}{
		{[]int{}, 0},
		{[]int{1}, 1},
		{[]int{1, 2}, 3},
	}

	for _, test := range tests {
		if got := Soma(test.input); got != test.want {
			t.Errorf("Soma(%v) = %v", test.input, got)
		}
	}
}

func TestSubtracao(t *testing.T) {
	var tests = []struct {
		input []int
		want  int
	}{
		{[]int{3, 2, 1}, 0},
		{[]int{10, 2, 3}, 5},
		{[]int{}, 0},
		{[]int{1, 2}, -1},
		{[]int{-1, -2, -3}, 4},
		{[]int{9, 3, 2, 1}, 3},
	}

	for _, test := range tests {
		if got := Subtracao(test.input); got != test.want {
			t.Errorf("Subtracao(%v) = %v", test.input, got)
		}
	}
}

func TestMultiplicacao(t *testing.T) {
	var tests = []struct {
		input []int
		want  int
	}{
		{[]int{1, 2, 3}, 6},
		{[]int{}, 0},
		{[]int{-2, 1, 4}, -8},
		{[]int{-2, -1, 4}, 8},
	}

	for _, test := range tests {
		if got := Multiplicacao(test.input); got != test.want {
			t.Errorf("Multiplicacao(%v) = %v", test.input, got)
		}
	}
}

func TestDivisao(t *testing.T) {
	var tests = []struct {
		input []int
		want  int
		err   error
	}{
		{[]int{5, 2}, 2, nil},
		{[]int{}, 0, nil},
		{[]int{0}, 0, nil},
		{[]int{0, 1}, 0, nil},
		{[]int{1, 0}, 0, DivisionByZeroError},
	}

	for _, test := range tests {
		got, err := Divisao(test.input)
		if got != test.want || err != test.err {
			t.Errorf("Divisao(%v) = %v (error=%v)", test.input, got, err)
		}
	}
}

func TestOperacao(t *testing.T) {
	var tests = []struct {
		input1 rune
		input2 []int
		want   int
		err    error
	}{
		{'+', []int{1, 2}, 3, nil},
		{'-', []int{1, 2}, -1, nil},
		{'*', []int{1, 2}, 2, nil},
		{'/', []int{1, 2}, 0, nil},
		{'=', []int{1, 2}, 0, UnknownOperator},
	}

	for _, test := range tests {
		got, err := Operacao(test.input1, test.input2)
		if got != test.want || err != test.err {
			t.Errorf("Operacao(%q, %v) = %v (error=%v)", string(test.input1), test.input2, got, err)
		}
	}
}

func TestMaior(t *testing.T) {
	var tests = []struct {
		input []int
		want  int
		err   error
	}{
		{[]int{0, 1, 100}, 100, nil},
		{[]int{0}, 0, nil},
		{[]int{}, 0, EmptySetError},
	}

	for _, test := range tests {
		got, err := Maior(test.input)

		if got != test.want || err != test.err {
			t.Errorf("Maior(%v) = %v", test.input, got)
		}
	}
}

func TestIntersecao(t *testing.T) {
	var tests = []struct {
		input1 []int
		input2 []int
		want   []int
	}{
		{[]int{}, []int{}, []int{}},
		{[]int{1, 2}, []int{3, 4}, []int{}},
		{[]int{1, 2}, []int{2, 3}, []int{2}},
	}

	for _, test := range tests {
		got := Intersecao(test.input1, test.input2)

		if !reflect.DeepEqual(got, test.want) {
			t.Errorf("Intersecao(%v, %v) = %v", test.input1, test.input2, got)
		}
	}
}
