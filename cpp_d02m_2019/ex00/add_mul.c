/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** add_mul
*/

#include <stdio.h>

void add_mul_4param(int first , int second , int *sum , int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int one = *first;
    int two = *second;

    *first = one + two;
    *second = one * two;
}