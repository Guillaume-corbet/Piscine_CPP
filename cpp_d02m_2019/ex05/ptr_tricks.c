/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** ptr_tricks
*/

#include <stdio.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1 , const int *ptr2)
{
    if (ptr2 > ptr1)
        return ((ptr2) - (ptr1));
    else
        return ((ptr1) - (ptr2));
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t str;
    whatever_t *ptr_str;
    whatever_t *ptr_dif = &str;

    ptr_str = (whatever_t *)(member_ptr - (&str.member - (int *) ptr_dif));
    return (ptr_str);
}