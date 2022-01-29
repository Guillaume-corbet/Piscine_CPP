/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title):Toy::Toy(title)
{
    //std::cout << "LittlePony Ctor" << std::endl;
}

LittlePony::~LittlePony()
{
    //std::cout << "LittlePony Dtor" << std::endl;
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}