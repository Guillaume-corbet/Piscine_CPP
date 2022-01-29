/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** main
*/

#include "ncurses/Terminal.hpp"
#include <string>
#include <iostream>
#include "ncurses/Ncurses.hpp"
#include "sfml/sfml.hpp"

int main(void)
{
    Ncurses ncurses;
    graph sfml;
    Data *data = new Data();

    ncurses.start(data);
    //sfml.start(data);
    return (0);
}