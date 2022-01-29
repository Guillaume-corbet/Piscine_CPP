/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** IAsteroid
*/

#pragma once

#include <string>
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class  IAsteroid
{
    public:
        virtual ~IAsteroid() {}
        virtual std::string beMined(DeepCoreMiner *miner) const = 0;
        virtual std::string beMined(StripMiner *miner) const = 0;
        virtual std::string getName() const = 0;
};