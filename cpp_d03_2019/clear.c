/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    int lenght = strlen(this->str);
    int i = 0;

    while (i < lenght) {
        this->str[i] = '\0';
        i = i + 1;
    }
}