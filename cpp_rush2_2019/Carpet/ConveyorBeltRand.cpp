/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ConveyorBeltRand
*/

#include "ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
}

void ConveyorBeltRand::randWrap(PapaXmasConveyorBelt *conv)
{
    int rande = rand() % 2;

    if (rande == 0) {
        conv->in(new Box());
    } else {
        conv->in(new GiftPaper());
    }
}

void ConveyorBeltRand::randObject(PapaXmasTable *table)
{
    int rande = rand() % 2;

    if (rande == 0) {
        table->put(new LittlePony("Rainbow Dash"));
    } else {
        table->put(new Teddy("Ted"));
    }
}