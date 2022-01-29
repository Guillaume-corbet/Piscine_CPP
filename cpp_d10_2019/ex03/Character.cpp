/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name):name(name)
{
}


Character::Character(const Character &old)
{
    this->materia = old.materia;
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    if (this->materia.size() > 3)
        return;
    this->materia.push_back(m);
}

void Character::unequip(int idx)
{
    if (this->materia.size() < (size_t)idx || this->materia.at(idx) == NULL)
        return;
    this->materia.erase(this->materia.begin() + idx);
}

void Character::use(int idx, ICharacter &target)
{
    if (this->materia.size() < (size_t)idx || this->materia.at(idx) == NULL)
        return;
    materia.at(idx)->use(target);
}