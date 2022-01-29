/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** func_ptr
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    write(1, str, strlen(str));
    write(1, "\n", 1);
}

void print_reverse(const char *str)
{
    int i = strlen(str) - 1;

    while (i > 0) {
        write(1, &str[i], 1);
        i = i - 1;
    }
    if (strlen(str) > 0) {
        write(1, &str[i], 1);
    }
    write(1, "\n", 1);
}

void print_upper(const char *str)
{
    int i = 0;
    char c = 'c';

    while (str[i] != '\0') {
        c = str[i] - 32;
        if (str[i] > 96 && str[i] < 123) {
            write(1, &c, 1);
        } else {
            write(1, &str[i], 1);
        }
        i = i + 1;
    }
    write(1, "\n", 1);
}

void print_42(const char *str)
{
    int length = 0;

    length = strlen(str);
    length = length + 1;
    write(1, "42\n", 3);
}

void do_action(action_t action, const char *str)
{
    void (*flag_tab[4])(const char *);

    flag_tab[0] = &print_normal;
    flag_tab[1] = &print_reverse;
    flag_tab[2] = &print_upper;
    flag_tab[3] = &print_42;
    flag_tab[action](str);
}