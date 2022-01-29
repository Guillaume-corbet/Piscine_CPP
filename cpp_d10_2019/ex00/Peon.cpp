/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon(std::string name):Victim::Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}