/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type):_type(type)
{
    this->_hp = hp;
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp = this->_hp - damage;
}

int AEnemy::getHP() const
{
    return (this->_hp);
}

std::string const AEnemy::getType() const
{
    return (this->_type);
}

void AEnemy::setHp(int hp)
{
    this->_hp = hp;
}