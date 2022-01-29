/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AsteroKreog
*/

#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog()
{
}

AsteroKreog::~AsteroKreog()
{
}

std::string AsteroKreog::beMined(DeepCoreMiner *miner) const
{
    return ("Sullite");
}

std::string AsteroKreog::beMined(StripMiner *miner) const
{
    return ("Kreogium");
}

std::string AsteroKreog::getName() const
{
    return ("AsteroKreog");
}
