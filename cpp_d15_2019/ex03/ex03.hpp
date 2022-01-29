/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <string>
#include <iostream>

template<typename T> void print(const T &a) { std::cout << a << std::endl; }

template<typename T> void foreach(T a[], void (*b)(const T &e), int c) { int d = 0; while (d < c) { b(a[d]); d = d + 1; } }

#endif /* !EX03_HPP_ */