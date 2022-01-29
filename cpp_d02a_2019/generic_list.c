/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list
*/

#include "generic_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    list_t tmp = list;
    unsigned int count = 0;

    while (tmp) {
        count = count + 1;
        tmp = tmp->next;
    }
    return (count);
}

bool list_is_empty(list_t list)
{
    if (!list)
        return (true);
    return (false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t tmp = list;

    while (tmp) {
        val_disp(tmp->value);
        tmp = tmp->next;
    }
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    list_t tmp = list;

    if (list == NULL)
        return (NULL);
    while (val_comp(value, tmp->value) != 0) {
        if (tmp == NULL)
            return (NULL);
        tmp = tmp->next;
    }
    return (tmp);
}

void list_clear(list_t *front)
{
    while ((*front) != NULL && (*front)->next != NULL) {
        list_del_elem_at_front(front);
    }
    (*front) = NULL;
}