/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** copy
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (pos > strlen(this->str))
        return (0);
    while (this->str[pos + i] != '\0' && i < n) {
        s[i] = this->str[pos + i];
        i = i + 1;
    }
    if (this->str[pos + i] == '\0' && i < n)
        i = i + 1;
    return (i);
}
