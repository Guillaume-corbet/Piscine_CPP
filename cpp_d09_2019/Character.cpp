/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level):name(name)
{
    this->Level = level;
    this->Health = 100;
    this->Energy = 100;
    this->Stamina = 5;
    this->Spirit = 5;
    this->Agility = 5;
    this->Strength = 5;
    this->Intelligence = 5;
    this->Range = Character::CLOSE;
    std::cout << name << " Created" << std::endl;
}

Character::Character(const std::string &name, int level, int stamina, int spirit, int agility, int strength, int intelligence):name(name)
{
    this->Level = level;
    this->Health = 100;
    this->Energy = 100;
    this->Stamina = stamina;
    this->Spirit = spirit;
    this->Agility = agility;
    this->Strength = strength;
    this->Intelligence = intelligence;
    this->Range = Character::CLOSE;
    std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
    
}

int Character::getLvl() const
{
    return (this->Level);
}

int Character::getPower() const
{
    return (this->Energy);
}

int Character::getPv() const
{
    return (this->Health);
}

const std::string &Character::getName() const
{
    return (this->name);
}

int Character::getStamina() const
{
    return (this->Stamina);
}

int Character::getStrength() const
{
    return (this->Strength);
}

int Character::getSpirit() const
{
    return (this->Spirit);
}

int Character::getAgility() const
{
    return (this->Agility);
}

int Character::getIntelligence() const
{
    return (this->Intelligence);
}

int Character::CloseAttack()
{
    if (this->Energy < 10) {
        std::cout << this->name << " out of power" << std::endl;
        return (0);
    }
    this->Energy = this->Energy - 10;
    std::cout << this->name << " strikes with a wooden stick" << std::endl;
    return (10 + this->Strength);
}

int Character::RangeAttack()
{
    if (this->Energy < 10) {
        std::cout << this->name << " out of power" << std::endl;
        return (0);
    }
    this->Energy = this->Energy - 10;
    std::cout << this->name << " tosses a stone" << std::endl;
    return (5 + this->Strength);
}

void Character::Heal()
{
    this->setHealth(this->Health + 50);
    std::cout << this->name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->Energy = 100;
    std::cout << this->name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->Health = this->Health - damage;
    if (this->Health < 1) {
        std::cout << this->name << " out of combat" << std::endl;
    } else {
        std::cout << this->name << " takes " << damage << " damage" << std::endl;
    }
}

void Character::setHealth(int health)
{
    if (health < 101)
        this->Health = health;
    else
        this->Health = 100;
}

void Character::setEnergy(int energy)
{
    if (energy < 101)
        this->Energy = energy;
    else
        this->Energy = 100;
}

void Character::setStrength(int strength)
{
    this->Strength = strength;
}