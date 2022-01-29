/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** drawing
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size,
uint32_t color)
{
    int x = 0;
    int y = 0;

    while (y < size) {
        while (x < size) {
            img[origin->x + x][origin->y + y] = color;
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
}
