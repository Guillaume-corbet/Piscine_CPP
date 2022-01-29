/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list4
*/

#include "generic_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t tmp = list;

    if (list == NULL)
        return (0);
    while (tmp->next) {
        tmp = tmp->next;
    }
    return (tmp->value);
}

void *list_get_elem_at_position(list_t list,
unsigned int position)
{
    unsigned int i = 0;
    list_t tmp = list;

    if (list == NULL)
        return (0);
    if (list_get_size(list) < position)
        return (false);
    while (i < position && tmp->next != NULL) {
        tmp = tmp->next;
        i = i + 1;
    }
    return (tmp->value);
}