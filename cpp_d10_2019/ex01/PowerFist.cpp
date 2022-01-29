/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** PowerFist
*/

#include "PowerFist.hpp"

PowerFist::PowerFist():AWeapon::AWeapon(std::string("Power Fist"), 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}