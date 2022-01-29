/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AMateria
*/

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type):_type(type)
{
    this->xp_ = 0;
}

AMateria::~AMateria()
{
}

unsigned int AMateria::getXP() const
{
    return (this->xp_);
}

const std::string &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    target.getName();
    this->xp_ = this->xp_ + 10;
}

void AMateria::setXP(int xp)
{
    if (xp < 0)
        this->xp_ = 0;
    else
        this->xp_ = xp;
}