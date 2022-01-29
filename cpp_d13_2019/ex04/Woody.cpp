/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string filename):Toy(Toy::ToyType::WOODY, name, filename)
{
}

Woody::~Woody()
{
}

void Woody::speak(std::string say)
{
    std::cout << "WOODY: " << this->getName() << " \"" << say << "\"" << std::endl;
}