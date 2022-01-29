/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** pyramid
*/

#include <stdio.h>
#include <stdlib.h>

int *change_path(int *path, int size)
{
    int x = size - 1;

    while (path[x] == 1) {
        path[x] = 0;
        x = x - 1;
    }
    path[x] = 1;
    return (path);
}

int *create_path(int size)
{
    int x = 0;
    int *path = malloc(sizeof(int) * size);

    while (x < size) {
        path[x] = 0;
        x = x + 1;
    }
    path[x] = -84;
    return (path);
}

int change_x(int x, int *path, int y)
{
    if (path[y] == 1)
        x = x + 1;
    return (x);
}

int pyramid_path(int size, int **map)
{
    int travel = 0;
    int result = 2147483647;
    int *path = create_path(size);
    int x = 0;
    int y = 0;

    while (path[0] == 0) {
        while (y < size) {
            x = change_x(x, path, y);
            travel = travel + map[y][x];
            y = y + 1;
        }
        if (travel < result)
            result = travel;
        travel = 0;
        path = change_path(path, size);
        y = 0;
        x = 0;
    }
    return (result);
}