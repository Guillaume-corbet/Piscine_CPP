/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    int lenght = strlen(this->str) + strlen(ap->str) + 1;
    char *new = malloc(sizeof(char) * lenght);

    new = strcpy(new, this->str);
    new = strcat(new, ap->str);
    string_destroy(this);
    string_init(this, new);
    free(new);
}

void append_c(string_t *this, const char *ap)
{
    int lenght = strlen(this->str) + strlen(ap) + 1;
    char *new = malloc(sizeof(char) * lenght);

    new = strcpy(new, this->str);
    new = strcat(new, ap);
    string_destroy(this);
    string_init(this, new);
    free(new);
}