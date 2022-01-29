/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Mixer
*/

#include "Mixer.hpp"

Mixer::Mixer()
{
    
}

Mixer::~Mixer()
{
}

int Mixer::mix(FruitBox &fruits) const
{
    int vit = 0;
    if (!this->_plugged)
        return (0);
    while (fruits.nbFruits() > 0) {
        vit = vit + fruits.pickFruit()->getVitamins();
    }
    return (vit);
}

void Mixer::setPlug(bool plug)
{
    this->_plugged = plug;
}