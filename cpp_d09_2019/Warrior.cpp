/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level):Character::Character(name, level, 12, 5, 7, 12, 6)
{
    this->weaponName = "hammer";
    this->Stamina = 12;
    this->Spirit = 5;
    this->Agility = 7;
    this->Strength = 12;
    this->Intelligence = 6;
    std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{

}

Warrior::Warrior(const std::string &name, int level, std::string weapon,int stamina, int spirit, int agility, int strength, int intelligence):Character::Character(name, level, stamina, spirit, agility, strength, intelligence)
{
    this->weaponName = weapon;
    std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack()
{
    if (this->getPower() < 30) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 30);
    std::cout << this->getName() << " strikes with his " << this->weaponName << std::endl;
    return (20 + this->getStrength());
}

int Warrior::RangeAttack()
{
    if (this->getPower() < 10) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setEnergy(this->getPower() - 10);
    std::cout << this->getName() << " intercepts" << std::endl;
    this->Range = Character::CLOSE;
    return (0);
}