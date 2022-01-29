/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list
*/

#include "double_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    double_list_t tmp = list;
    unsigned int count = 0;

    while (tmp) {
        count = count + 1;
        tmp = tmp->next;
    }
    return (count);
}

bool double_list_is_empty(double_list_t list)
{
    if (!list)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    double_list_t tmp = list;

    while (tmp) {
        printf("%f\n", tmp->value);
        tmp = tmp->next;
    }
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    double_list_t tmp = list;

    if (list == NULL)
        return (NULL);
    while (tmp->value != value) {
        if (tmp == NULL)
            return (NULL);
        tmp = tmp->next;
    }
    return (tmp);
}