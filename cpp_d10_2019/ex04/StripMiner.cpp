/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** StripMiner
*/

#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::~StripMiner()
{
}

void StripMiner::mine(IAsteroid *asteroid)
{
    std::cout << "* strip mining... got " << asteroid->beMined(this) << "! *" << std::endl;
}