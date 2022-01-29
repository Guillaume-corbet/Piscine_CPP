/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** nem_ptr
*/

#include "mem_ptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_str(const char *str1 , const char *str2 , char **res)
{
    int lenght = strlen(str1) + strlen(str2) + 1;
    int i = 0;

    *res = malloc(sizeof(char) * (lenght));
    while (str1[i] != '\0') {
        (*res)[i] = str1[i];
        i = i + 1;
    }
    i = 0;
    while (str2[i] != '\0') {
        (*res)[strlen(str1) + i] = str2[i];
        i = i + 1;
    }
}

void add_str_struct(str_op_t *str_op)
{
    int lenght = strlen(str_op->str1) + strlen(str_op->str2) + 1;
    int i = 0;

    str_op->res = malloc(sizeof(char) * lenght);
    while (str_op->str1[i] != '\0') {
        str_op->res[i] = str_op->str1[i];
        i = i + 1;
    }
    i = 0;
    while (str_op->str2[i] != '\0') {
        str_op->res[strlen(str_op->str1) + i] = str_op->str2[i];
        i = i + 1;
    }
}