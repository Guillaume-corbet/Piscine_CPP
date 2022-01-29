/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** tab_to_2dtab
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int x = 0;
    int y = 0;
    int i = 0;

    (*res) = malloc(sizeof(int *) * length);

    while (y < length) {
        (*res)[y] = malloc(sizeof(int) * width);
        while (x < width) {
            (*res)[y][x] = tab[i];
            x = x + 1;
            i = i + 1;
        }
        x = 0;
        y = y + 1;
    }
}