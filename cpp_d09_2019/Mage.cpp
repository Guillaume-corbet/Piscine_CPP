/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level):Character::Character(name, level, 6, 11, 7, 6, 12)
{
    this->Stamina = 6;
    this->Spirit = 11;
    this->Agility = 7;
    this->Strength = 6;
    this->Intelligence = 12;
    std::cout << this->getName() << " teleported" << std::endl;
}

Mage::Mage(const std::string &name, int level, int Stamina, int Spirit, int Agility, int strength, int intelligence):Character::Character(name, level, Stamina, Spirit, Agility, strength, intelligence)
{
    std::cout << this->getName() << " teleported" << std::endl;
}

Mage::~Mage()
{

}

int Mage::CloseAttack()
{
    if (this->getPower() < 10) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 10);
    std::cout << this->getName() << " blinks" << std::endl;
    this->Range = Character::RANGE;
    return (0);
}

int Mage::RangeAttack()
{
    if (this->getPower() < 25) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 25);
    std::cout << this->getName() << " launches a fire ball" << std::endl;
    return (20 + this->getSpirit());
}

void Mage::RestorePower()
{
    this->setEnergy(this->getPower() + 50 + this->getIntelligence());
    std::cout << this->getName() << " takes a mana potion" << std::endl;
}