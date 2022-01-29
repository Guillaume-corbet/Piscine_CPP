/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name):_name(name)
{
    this->_AP = 40;
    this->_weapon = NULL;
}

Character::~Character()
{
}

void Character::recoverAP()
{
    this->setAP(this->_AP + 10);
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

std::string const Character::getName() const
{
    return (this->_name);
}

void Character::attack(AEnemy *enemy)
{
    if (this->_weapon == NULL)
        return;
    if (this->_weapon->getAPCost() > this->_AP)
        return;
    this->_AP = this->_AP - this->_weapon->getAPCost();
    enemy->takeDamage(this->_weapon->getDamage());
    std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
    this->_weapon->attack();
    if (enemy->getHP() < 1)
        delete(enemy);
}

void Character::setAP(int ap)
{
    if (ap > 40)
        ap = 40;
    else if (ap < 0)
        ap = 0;
    else
        this->_AP = ap;
}

int Character::getAP() const
{
    return (this->_AP);
}

AWeapon *Character::getWeapon() const
{
    if (this->_weapon == NULL)
        return (NULL);
    return (this->_weapon);
}

std::ostream &operator<<(std::ostream &s, const Character &tmp)
{
    s << tmp.getName() << " has " << tmp.getAP() << " AP and";
    if (tmp.getWeapon() == NULL)
        s << " is unarmed" << std::endl;
    else
        s << " wields a " << tmp.getWeapon()->getName() << std::endl;
    return (s);
}