/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon():Fruit("lemon", 3)
{
}

Lemon::Lemon(std::string name, int vitamins):Fruit(name, vitamins)
{

}

Lemon::~Lemon()
{
}
