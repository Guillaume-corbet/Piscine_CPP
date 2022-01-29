/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** find
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int i = pos;
    int y = 0;

    if (strlen(str->str) > strlen(this->str) || pos >= strlen(this->str))
        return (-1);
    while (this->str[i] != '\0') {
        while (this->str[i + y] != '\0' && str->str[y] != '\0'
        && this->str[i + y] == str->str[y]) {
            y = y + 1;
        }
        if (str->str[y] == '\0')
            return (i);
        y = 0;
        i = i + 1;
    }
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int i = pos;
    int y = 0;

    if (strlen(str) > strlen(this->str) || pos >= strlen(this->str))
        return (-1);
    while (this->str[i] != '\0') {
        while (this->str[i + y] != '\0' && str[y] != '\0'
        && this->str[i + y] == str[y]) {
            y = y + 1;
        }
        if (str[y] == '\0')
            return (i);
        y = 0;
        i = i + 1;
    }
    return (-1);
}