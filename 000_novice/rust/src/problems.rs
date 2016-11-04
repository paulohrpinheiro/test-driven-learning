//! Test Driven Learning Project.
//! Desenvolva TDD e programação com TDD e programação!
//! Módulo novice.
//!
//! The MIT License (MIT)
//!
//! Copyright (c) 2016 Paulo Henrique Rodrigues Pinheiro <paulohrpinheiro@gmail.com>
//!
//! Permission is hereby granted, free of charge, to any person obtaining a copy
//! of this software and associated documentation files (the "Software"), to deal
//! in the Software without restriction, including without limitation the rights
//! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//! copies of the Software, and to permit persons to whom the Software is
//! furnished to do so, subject to the following conditions:
//!
//! The above copyright notice and this permission notice shall be included in all
//! copies or substantial portions of the Software.
//!
//! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//! SOFTWARE.


// Inclua os módulos que precisar aqui:


/// A função `negue` deve receber um valor boleano (verdadeiro ou falso) e
/// retornar a negação desse valor.
///
/// # Examples
///
/// ```
/// extern crate rust;
/// assert_eq!(true, rust::problems::negue(false));
/// assert_eq!(false, rust::problems::negue(true));
/// ```
pub fn negue(value:bool) -> bool {
    false
}


/// A função `diga_ola` deve ser escrita de tal forma que receba como
/// parâmetro um argumento *string*. Deve retornar a *string* "Olá, ", seguida
/// do argumento recebido, mais um ponto final. A *string* recebida deve estar
/// limpa, ou seja, sem caracteres de espaço no começo ou no fim. Se a *string*
/// estiver vazia, retorna apenas "Olá!"
///
/// # Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!("Olá!", rust::problems::diga_ola(""));
/// assert_eq!("Olá!", rust::problems::diga_ola("    "));
/// assert_eq!("Olá, Paulo.", rust::problems::diga_ola("Paulo"));
/// assert_eq!("Olá, Paulo.", rust::problems::diga_ola("  Paulo  "));
/// assert_eq!("Olá, Paulo Henrique.", rust::problems::diga_ola("  Paulo Henrique  "));
/// ```
pub fn diga_ola(nome:&str) -> String {
    "".to_string()
}


/// A função `lista_numeros_pares` deve receber um parâmetro numérico
/// inteiro que determina quantos números pares devem estar em um array que
/// será o retorno da função.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(0, rust::problems::lista_numeros_pares(0).len());
/// assert_eq!(vec![2], rust::problems::lista_numeros_pares(1));
/// assert_eq!(vec![2, 4, 6, 8], rust::problems::lista_numeros_pares(4));
/// assert_eq!(vec![2, 4, 6, 8, 10], rust::problems::lista_numeros_pares(5));
/// assert_eq!(0, rust::problems::lista_numeros_pares(-1).len());
/// ```
pub fn lista_numeros_pares(quantos:i32) -> Vec<i32> {
    vec![]
}


/// A função `lista_multiplos` deve receber dois parâmetros numéricos
/// inteiros e retornar uma lista de números inteiros. O tamanho da lista é
/// determinado pelo primeiro parâmetro, e o número base será o segundo
/// parâmetro.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(0, rust::problems::lista_multiplos(0, 10).len());
/// assert_eq!(0, rust::problems::lista_multiplos(-1, 10).len());
/// assert_eq!(vec![-3, -2, -1], rust::problems::lista_multiplos(3, -1));
/// assert_eq!(0, rust::problems::lista_multiplos(3, 0).len());
/// assert_eq!(vec![10, 20, 30], rust::problems::lista_multiplos(3, 10));
/// ```
pub fn lista_multiplos(quantos:i32, base:i32) -> Vec<i32> {
    vec![]
}


/// A função `soma` deve receber um *array* de números inteiros, e retornar
/// a sua soma. Se a lista for vazia, deve retornar zero.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(0, rust::problems::soma(vec![]));
/// assert_eq!(1, rust::problems::soma(vec![1]));
/// assert_eq!(3, rust::problems::soma(vec![1, 2]));
/// ```
pub fn soma(lista:Vec<i32>) -> i32 {
    -1
}


/// A função `subtracao` deve receber um *array* de números inteiros, e
/// retornar a subtração de todos os elementos em sequência. Por exemplo,
/// subtracao([3,2,1]) deve retornar 0, e subtracao([10,2,3]) deve retornar 5.
/// Se a lista for vazia, deve retornar zero.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(0, rust::problems::subtracao(vec![3, 2, 1]));
/// assert_eq!(5, rust::problems::subtracao(vec![10, 2, 3]));
/// assert_eq!(0, rust::problems::subtracao(vec![]));
/// assert_eq!(-1, rust::problems::subtracao(vec![1, 2]));
/// assert_eq!(4, rust::problems::subtracao(vec![-1, -2, -3]));
/// assert_eq!(3, rust::problems::subtracao(vec![9, 3, 2, 1]));
/// ```
pub fn subtracao(lista:Vec<i32>) -> i32 {
    -1
}


/// A função `multiplicação` deve receber um *array* de números inteiros, e
/// retornar o seu produto. Se a lista for vazia, deve retornar zero.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(6, rust::problems::multiplicacao(vec![1, 2, 3]));
/// assert_eq!(0, rust::problems::multiplicacao(vec![]));
/// assert_eq!(-8, rust::problems::multiplicacao(vec![-2, 1, 4]));
/// assert_eq!(8, rust::problems::multiplicacao(vec![-2, -1, 4]));
pub fn multiplicacao(lista:Vec<i32>) -> i32 {
    -1
}


/// A função `divisao` deve receber um *array* de números inteiros, e
/// retornar o resultado da sequência de divisões por cada elemento. Por
/// exemplo, divisão([16, 4, 2]) deve retornar 2, e divisão([100,2,10]) deve
/// retornar 5. Se a lista for vazia, deve retornar zero.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(2, rust::problems::divisao(vec![5, 2]));
/// assert_eq!(0, rust::problems::divisao(vec![]));
/// assert_eq!(0, rust::problems::divisao(vec![0]));
/// assert_eq!(2, rust::problems::divisao(vec![16, 4, 2]));
/// assert_eq!(5, rust::problems::divisao(vec![100, 2, 10]));
/// assert_eq!(0, rust::problems::divisao(vec![0, 1]));
/// //assert_eq!(0, rust::problems::divisao(vec![1, 0]));
pub fn divisao(lista:Vec<i32>) ->i32 {
    -1
}


/// A função `maior` deve receber um *array* de números inteiros e retornar
/// qual é o maior deles.
///
/// Examples
///
/// ```
/// extern crate rust;
///
/// assert_eq!(100, rust::problems::maior(vec![0, 1 ,100]));
/// assert_eq!(0, rust::problems::maior(vec![0]));
pub fn maior(lista:Vec<i32>)-> i32 {
    -1
}


/// A função `intersecao` deve receber dois *arrays* contendo números
/// inteiros, e retornar a interseção entre os conjuntos, ou seja, um *array*
/// que contenha apenas os números que estejam contidos nos dois *arrays*
/// passados para a função.
///
/// Examples
///
/// ```
/// assert_eq!(0, rust::problems::intersecao(vec![], vec![]).len());
/// assert_eq!(0, rust::problems::intersecao(vec![1, 2], vec![3, 4]).len());
/// assert_eq!(vec![2], rust::problems::intersecao(vec![1, 2], vec![2, 3]));
pub fn intersecao(a:Vec<i32>, b:Vec<i32>) -> Vec<i32> {
    vec![]
}
