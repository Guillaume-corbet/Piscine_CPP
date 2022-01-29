/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Ice
*/

#include "Ice.hpp"

Ice::Ice():AMateria::AMateria("ice")
{

}

Ice::~Ice()
{

}

AMateria *Ice::clone() const
{
    AMateria *ice = new Ice();
    return (ice);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    this->setXP(this->getXP() + 10);
}