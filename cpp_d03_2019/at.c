/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    size_t length = strlen(this->str) - 1;

    if (length < pos)
        return (-1);
    return (this->str[pos]);
}