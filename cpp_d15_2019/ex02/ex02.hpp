/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>
#include <string>

template<typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    if (b < a)
        return (b);
    else
        return (a);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (b < a)
        return (b);
    else
        return (a);
}

template<typename T>
T templateMin(T a[], int size)
{
    int i = 2;
    T minus;

    if (size > 1)
        minus = min<T>(a[0], a[1]);
    else
        return (a[0]);
    while (i < size) {
        minus = min<T>(minus, a[i]);
        i = i + 1;
    }
    return minus;
}

int nonTemplateMin(int a[], int size)
{
    int i = 0;
    int minus = __INT_MAX__;

    if (size > 1)
        minus = min(a[0], a[1]);
    else
        return (a[0]);
    if (size == 2)
        return (minus);
    while (i < size) {
        minus = min(minus, a[i]);
        i = i + 1;
    }
    return (minus);
}

#endif /* !EX02_HPP_ */
