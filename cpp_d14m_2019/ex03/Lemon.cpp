/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon():Fruit(3, "lemon")
{
}

Lemon::Lemon(int vitamins, std::string name):Fruit(vitamins, name)
{

}

Lemon::~Lemon()
{
}
