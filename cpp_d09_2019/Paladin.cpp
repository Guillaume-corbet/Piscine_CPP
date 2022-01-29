/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level):Character(name, level, 10, 10, 2, 9, 10), Warrior(name, level, "hammer",10, 10, 2, 9, 10), Priest(name, level, 10, 10, 2, 9, 10)
{
    this->Stamina = 10;
    this->Spirit = 10;
    this->Agility = 2;
    this->Strength = 9;
    this->Intelligence = 10;
    std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{

}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}