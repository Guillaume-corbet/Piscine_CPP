/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** to_int
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (this != NULL && this->str != NULL)
        return (atoi(this->str));
    return (0);
}