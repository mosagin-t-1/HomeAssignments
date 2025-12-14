# Assignment 5

## Author
Тимофей Мосягин, Б-81  
st142155@student.spbu.ru

## Description
Home assignment 5.

Implements a template class `Matrix<M, N, T>` for working with matrices of fixed size.

Supported operations:
- Matrix addition
- Matrix multiplication
- Multiplication by scalar
- Transposition

The matrix class is tested using Google Test with:
- basic integer types (`int`)
- floating point types (`double`)
- custom user-defined type `Rational`

The `Rational` class represents rational numbers and preserves its invariants
(non-zero denominator, normalized form).

Memory management is handled automatically using standard library containers.

## Build
make

## Run
./Assignment5

## Tests
make test_rational  
make test_matrix

## Clean
make clean

