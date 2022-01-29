/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list2
*/

#include "generic_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));

    if (!new)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t tmp = *front_ptr;
    list_t new = malloc(sizeof(node_t));

    if (!new)
        return (false);
    if (!tmp) {
        new->value = elem;
        new->next = NULL;
        *front_ptr = new;
        return (true);
    }
    while (tmp->next) {
        tmp = tmp->next;
    }
    new->value = elem;
    new->next = NULL;
    tmp->next = new;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t new = malloc(sizeof(node_t));
    unsigned int i = 1;

    if (list_get_size(*front_ptr) < position)
        return (false);
    while (i < position && tmp->next != NULL) {
        tmp = tmp->next;
        i = i + 1;
    }
    if (tmp->next == NULL) {
        list_add_elem_at_back(front_ptr, elem);
    } else if (position == 0) {
        list_add_elem_at_front(front_ptr, elem);
    } else {
        new->value = elem;
        new->next = tmp->next;
        tmp->next = new;
    }
    return (true);
}