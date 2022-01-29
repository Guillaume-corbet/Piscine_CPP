/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** div
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    a = a - (a % b);
    return (a / b);
}

float decimale_div(int a, int b)
{
    float result;

    if (b == 0)
        return (0);
    result = ((float) a) / ((float) b);
    return (result);
}

void exec_div(division_t *operation)
{
    integer_op_t *integer;
    decimale_op_t *decimal;

    if (operation->div_type == INTEGER) {
        integer = operation->div_op;
        integer->res = integer_div(integer->a, integer->b);
    } else if (operation->div_type == DECIMALE) {
        decimal = operation->div_op;
        decimal->res = decimale_div(decimal->a, decimal->b);
    }
}