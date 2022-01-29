/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level):Character::Character(name, level, 4, 21, 2, 4, 42), Mage::Mage(name, level, 4, 21, 2, 4, 42)
{
    this->Stamina = 4;
    this->Spirit = 21;
    this->Agility = 2;
    this->Strength = 12;
    this->Intelligence = 6;
    std::cout << this->getName() << " enters in the order" << std::endl;
}

Priest::~Priest()
{

}

Priest::Priest(const std::string &name, int lvl, int stamina, int spirit, int agility, int strength, int intell):Character::Character(name, lvl, strength, spirit, agility, stamina, intell), Mage::Mage(name, lvl, strength, spirit, agility, stamina, intell)
{
    std::cout << this->getName() << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
    if (this->getPower() < 10) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 10);
    this->Range = Character::RANGE;
    std::cout << this->getName() << " uses a spirit explosion" << std::endl;
    return (10 + this->getSpirit());
}

void Priest::Heal()
{
    if (this->getPower() < 10) {
        std::cout << this->getName() << " out of power" << std::endl;
        return;
    }
    this->setEnergy(this->getPower() - 10);
    this->setHealth(70 + getPv());
    std::cout << this->getName() << " casts a little heal spell" << std::endl;
}