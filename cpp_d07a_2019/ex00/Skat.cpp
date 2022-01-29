/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_stimpacks = stimPaks;
}

Skat::~Skat()
{

}

int &Skat::stimPaks()
{
    return (this->_stimpacks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_stimpacks) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        stock = stock + number;
        this->_stimpacks = this->_stimpacks - number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_stimpacks = this->_stimpacks + number;
}

void Skat::useStimPaks()
{
    if (this->_stimpacks > 0) {
        this->_stimpacks = this->_stimpacks - 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimpacks << " stimpaks remaining sir!" << std::endl;
}