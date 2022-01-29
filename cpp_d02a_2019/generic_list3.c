/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list3
*/

#include "generic_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (front_ptr == NULL)
        return (false);
    *front_ptr = tmp->next;
    free(tmp);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t tmp2;

    if (front_ptr == NULL)
        return (false);
    while (tmp->next) {
        if (tmp->next->next == NULL)
            tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    free(tmp);
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr,
unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t tmp2;
    unsigned int i = 0;

    if (list_get_size(*front_ptr) < position)
        return (false);
    while (i < position && tmp->next != NULL) {
        if (i + 1 == position)
            tmp2 = tmp;
        tmp = tmp->next;
        i = i + 1;
    }
    if (tmp->next == NULL) {
        list_del_elem_at_back(front_ptr);
    } else if (position == 0) {
        list_del_elem_at_front(front_ptr);
    } else {
        tmp2->next = tmp->next;
        free(tmp);
    }
    return (true);
}