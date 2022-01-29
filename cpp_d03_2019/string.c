/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** string
*/

#include "string.h"

void string_init_2(string_t *new)
{
    new->assign_s = &assign_s;
    new->assign_c = &assign_c;
    new->append_s = &append_s;
    new->append_c = &append_c;
    new->at = &at;
    new->clear = &clear;
    new->size = &size;
    new->compare_s = &compare_s;
    new->compare_c = &compare_c;
    new->copy = &copy;
    new->c_str = &c_str;
    new->empty = &empty;
    new->find_s = &find_s;
    new->find_c = &find_c;
    new->insert_c = &insert_c;
    new->insert_s = &insert_s;
    new->to_int = &to_int;
    new->split_s = &split_s;
    new->split_c = &split_c;
    new->print = &print;
}

void string_init(string_t *this, const char *s)
{
    string_t *new = malloc(sizeof(string_t));

    new->str = malloc(sizeof(char) * (strlen(s) + 1));
    new->str = strcpy(new->str, s);
    string_init_2(new);
    *this = *new;
    free(new);
}

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}