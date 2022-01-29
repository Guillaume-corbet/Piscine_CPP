/*
** EPITECH PROJECT, 2019
** cppPool
** File description:
** main.c
*/

#include "menger.h"

int error(int size, int level)
{
    int i = 1;
    int count = 0;

    while (i < size) {
        i = i * 3;
        count = count + 1;
    }
    if (i != size && level > count) {
        return (84);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int square_size = 0;
    int level = 0;

    if (argc != 3)
        return (84);
    square_size = atoi(argv[1]);
    level = atoi(argv[2]);
    if (square_size < 1 || error(square_size, level) == 84 || level < 1)
        return (84);
    menger(square_size, level, 0, 0);
    return (0);
}