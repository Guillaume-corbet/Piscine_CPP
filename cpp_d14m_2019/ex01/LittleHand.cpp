/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *f;
    FruitBox box(unsorted.getSize());
    while (unsorted.nbFruits() > 0) {
        f = unsorted.pickFruit();
        if (f->getName() == "lemon" || f->getName() == "rotten lemon") {
            if (!lemons.putFruit(f)) {
                box.putFruit(f);
            }
        } else if (f->getName() == "lime") {
            if (!limes.putFruit(f)) {
                box.putFruit(f);
            }
        } else if (f->getName() == "banana") {
            if (!bananas.putFruit(f)) {
                box.putFruit(f);
            }
        } else {
            box.putFruit(f);
        }
    }
    while (box.nbFruits() > 0) {
        unsorted.putFruit(box.pickFruit());
    }
}