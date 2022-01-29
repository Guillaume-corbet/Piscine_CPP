/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title):Object::Object(title, "object")
{
    //std::cout << "Toy Ctor" << std::endl;
}

Toy::~Toy()
{
    //std::cout << "Toy Dtor" << std::endl;
}

void Toy::isTaken() const
{
    //std::cout << "Toy Taken" << std::endl;
}