/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string filename):Toy(Toy::ToyType::BUZZ, name, filename)
{

}

Buzz::~Buzz()
{

}

void Buzz::speak(std::string say)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << say << "\"" << std::endl;
}