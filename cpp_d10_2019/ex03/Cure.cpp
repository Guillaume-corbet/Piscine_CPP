/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Cure
*/

#include "Cure.hpp"

Cure::Cure():AMateria::AMateria("cure")
{
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
    AMateria *cure = new Cure();
    return (cure);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    this->setXP(this->getXP() + 10);
}