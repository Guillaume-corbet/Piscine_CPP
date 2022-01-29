/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** KoalaSteroid
*/

#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid()
{
}

KoalaSteroid::~KoalaSteroid()
{
}

std::string KoalaSteroid::beMined(DeepCoreMiner *miner) const
{
    return ("Zazium");
}

std::string KoalaSteroid::beMined(StripMiner *miner) const
{
    return ("Koalite");
}

std::string KoalaSteroid::getName() const
{
    return ("KoalaSteroid");
}