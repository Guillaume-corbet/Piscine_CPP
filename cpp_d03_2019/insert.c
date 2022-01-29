/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** insert
*/

#include "string.h"

char *insert_str(char *new, const char *str, int k, size_t *i)
{
    while (str[k] != '\0') {
        new[(*i)] = str[k];
        (*i) = (*i) + 1;
        k = k + 1;
    }
    return new;
}

void insert_c(string_t *this , size_t pos , const char *str)
{
    size_t i = 0;
    size_t y = 0;
    size_t k = 0;
    int len = strlen(this->str) + strlen(str) + 1;
    char *new = malloc(sizeof(char) * len);

    while (i < pos && this->str[i] != '\0') {
        new[i] = this->str[i];
        i = i + 1;
    }
    y = i;
    new = insert_str(new, str, k, &i);
    while (this->str[y] != '\0') {
        new[i] = this->str[y];
        i = i + 1;
        y = y + 1;
    }
    new[i] = '\0';
    string_destroy(this);
    string_init(this, new);
    free(new);
}

void insert_s(string_t *this , size_t pos , const string_t *str)
{
    size_t i = 0;
    size_t y = 0;
    size_t k = 0;
    int len = strlen(this->str) + strlen(str->str) + 1;
    char *new = malloc(sizeof(char) * len);

    while (i < pos && this->str[i] != '\0') {
        new[i] = this->str[i];
        i = i + 1;
    }
    y = i;
    new = insert_str(new, str->str, k, &i);
    while (this->str[y] != '\0') {
        new[i] = this->str[y];
        i = i + 1;
        y = y + 1;
    }
    new[i] = '\0';
    string_destroy(this);
    string_init(this, new);
    free(new);
}