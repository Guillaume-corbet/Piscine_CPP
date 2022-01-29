/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template<typename T>
T max(T a, T b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

template<typename T>
T add(T a, T b)
{
    return (a + b);
}

template<typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

#endif /* !EX00_HPP_ */