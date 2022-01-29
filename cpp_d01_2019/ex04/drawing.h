/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** drawing
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <inttypes.h>
#include <unistd.h>

typedef struct point
{
    unsigned int x;
    unsigned int y;
}point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size,
uint32_t color);

#endif /* !DRAWING_H_ */