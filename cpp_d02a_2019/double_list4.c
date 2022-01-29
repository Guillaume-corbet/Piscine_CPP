/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list4
*/

#include "double_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t tmp = list;

    if (list == NULL)
        return (0);
    while (tmp->next) {
        tmp = tmp->next;
    }
    return (tmp->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    unsigned int i = 0;
    double_list_t tmp = list;

    if (list == NULL)
        return (0);
    if (double_list_get_size(list) < position)
        return (false);
    while (i < position && tmp->next != NULL) {
        tmp = tmp->next;
        i = i + 1;
    }
    return (tmp->value);
}