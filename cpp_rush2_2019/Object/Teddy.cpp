/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title):Toy::Toy(title)
{
    //std::cout << "Teddy Ctor" << std::endl;
}

Teddy::~Teddy()
{
    //std::cout << "Teddy Dtor" << std::endl;
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}