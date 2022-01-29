/*
** EPITECH PROJECT, 2019
** cppPool
** File description:
** menger.c
*/

#include "menger.h"

void menger(int size, int level, int x, int y)
{
    level = level - 1;
    printf("%03i %03i %03i\n", size / 3, x + size / 3, y + size / 3);
    if (level == 0)
        return;
    menger(size / 3, level, x, y);
    menger(size / 3, level, x, y + size / 3);
    menger(size / 3, level, x, y + (size / 3) * 2);
    menger(size / 3, level, x + size / 3, y);
    menger(size / 3, level, x + size / 3, y + (size / 3) * 2);
    menger(size / 3, level, x + (size / 3) * 2, y);
    menger(size / 3, level, x + (size / 3) * 2, y + size / 3);
    menger(size / 3, level, x + (size / 3) * 2, y + (size / 3) * 2);
}