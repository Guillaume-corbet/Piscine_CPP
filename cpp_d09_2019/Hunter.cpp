/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level):Character::Character(name, level, 9, 6, 25, 9, 5), Warrior::Warrior(name, level, "sword", 9, 6, 25, 9, 5)
{
    this->Stamina = 9;
    this->Spirit = 6;
    this->Agility = 25;
    this->Strength = 9;
    this->Intelligence = 5;
    std::cout << name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{

}

int Hunter::RangeAttack()
{
    if (this->getPower() < 25) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 25);
    std::cout << this->getName() << " uses his bow" << std::endl;
    return (20 + this->getAgility());
}

void Hunter::RestorePower()
{
    this->setEnergy(100);
    std::cout << this->getName() << " meditates" << std::endl;
}