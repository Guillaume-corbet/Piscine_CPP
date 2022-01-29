/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** split
*/

#include "string.h"

void intern_while_one(int *i, int *y, int *x, int a)
{
    if (a == 1) {
        *i = *i + 1;
        *y = *y + 1;
    } else if (a == 2) {
        *y = 0;
        *x = *x + 1;
    }
}

string_t **str_to_word_array_string_t(char *str, char c)
{
    string_t **tab;
    int i = 0;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(string_t *) * strlen(str) + 1)) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        tab[x] = malloc(sizeof(string_t));
        tab[x]->str = malloc(sizeof(char) * strlen(str) + 1);
        tab[x]->str = memset(tab[x]->str, '\0', strlen(str) + 1);
        while (str[i] != '\0' && str[i] != c) {
            tab[x]->str[y] = str[i];
            intern_while_one(&i, &y, &x, 1);
        }
        if (str[i] != '\0')
            i = i + 1;
        intern_while_one(&i, &y, &x, 2);
    }
    tab[x] = NULL;
    return (tab);
}

char **str_to_word_array_sec(char *str, char c)
{
    char **tab;
    int i = 0;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(char *) * strlen(str))) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if ((tab[x] = malloc(sizeof(char) * strlen(str) + 1)) == NULL)
            return (NULL);
        tab[x] = memset(tab[x], '\0', strlen(str) + 1);
        while (str[i] != '\0' && str[i] != c) {
            tab[x][y] = str[i];
            intern_while_one(&i, &y, &x, 1);
        }
        if (str[i] != '\0')
            i = i + 1;
        intern_while_one(&i, &y, &x, 2);
    }
    tab[x] = NULL;
    return (tab);
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **tab;

    if (strlen(this->str) == 0 ||
    (this->str[0] == separator && strlen(this->str) == 1)) {
        tab = malloc(sizeof(string_t *) * 2);
        tab[0] = malloc(sizeof(string_t));
        tab[0]->str = malloc(sizeof(char) * 1);
        tab[0]->str[0] = '\0';
        tab[1] = NULL;
        return tab;
    }
    tab = str_to_word_array_string_t(this->str, separator);
    if (tab == NULL)
        return (NULL);
    return (tab);
}

char **split_c(const string_t *this, char separator)
{
    char **tab;

    if (strlen(this->str) == 0) {
        tab = malloc(sizeof(char *) * 2);
        tab[0] = malloc(sizeof(char) * 1);
        tab[0][0] = '\0';
        tab[1] = NULL;
        return tab;
    }
    tab = str_to_word_array_sec(this->str, separator);
    if (tab == NULL)
        return (NULL);
    return (tab);
}
