/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    string_destroy(this);
    string_init(this, str->str);
}

void assign_c(string_t *this, const char *c)
{
    string_destroy(this);
    string_init(this, c);
}