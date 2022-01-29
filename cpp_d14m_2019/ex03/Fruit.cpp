/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit()
{

}

Fruit::Fruit(int vitamins, std::string name)
{
    this->_vitamins = vitamins;
    this->_name = name;
}

Fruit::~Fruit()
{

}

int Fruit::getVitamins() const
{
    return (this->_vitamins);
}

std::string Fruit::getName() const
{
    return (this->_name);
}