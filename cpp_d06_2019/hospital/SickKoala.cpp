/*
** EPITECH PROJECT, 2020
** day6
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name <<
    ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" <<
    std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str.compare("Mars") == 0) {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" <<
        std::endl;
        return (true);
    } else if (str.compare("Buronzand") == 0) {
        std::cout << "Mr." << this->name << ": And you'll sleep right away!" <<
        std::endl;
        return (true);
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    size_t pos = 0;

    pos = str.find("Kreog!");
    while (pos != std::string::npos) {
        str.replace(pos, sizeof("Kreog!") - 1, "1337!");
        pos = str.find("Kreog!");
    }
    std::cout << "Mr." << this->name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}