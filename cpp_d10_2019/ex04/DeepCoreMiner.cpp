/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** DeepCoreMiner
*/

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{

}

DeepCoreMiner::~DeepCoreMiner()
{

}

void DeepCoreMiner::mine(IAsteroid *asteroid)
{
    std::cout << "* mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}