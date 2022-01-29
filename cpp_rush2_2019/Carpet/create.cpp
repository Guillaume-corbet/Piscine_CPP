/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** create
*/

#include "create.hpp"

Itable *createTable()
{
    Itable *table = new PapaXmasTable();
    return (table);
}

IconveyorBelt *createConvoyerBelt()
{
    IconveyorBelt *convoyer = new PapaXmasConveyorBelt();
    return (convoyer);
}