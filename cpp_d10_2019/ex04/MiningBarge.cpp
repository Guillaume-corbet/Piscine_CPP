/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** MiningBarge
*/

#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
}

MiningBarge::~MiningBarge()
{
}

void MiningBarge::equip(IMiningLaser *laser)
{
    if (this->laser.size() < 4)
        this->laser.push_back(laser);
}

void MiningBarge::mine(IAsteroid *asteroid) const
{
    int i = 0;

    while (i < laser.size()) {
        laser.at(i)->mine(asteroid);
        i = i + 1;
    }
}