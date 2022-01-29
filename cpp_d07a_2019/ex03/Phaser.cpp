/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Phaser
*/

#include "Phaser.hpp"

Phaser::Phaser(int MaxAmmo, AmmoType type)
{
    this->_maxAmmo = MaxAmmo;
    this->_loadedAmmo = MaxAmmo;
    this->_type = type;
    std::string tab[3] = {"regular", "plasma", "rocket"};
    this->_sound = new Sounds();

    for (int i = 0; i < MaxAmmo; i++)
        _magazine.push_back(tab[type]);
}


Phaser::~Phaser()
{
    
}

void Phaser::changeType(AmmoType newType)
{
    std::string str[3] = {"regular", "plasma", "rocket"};
    std::cout << "Switching ammo to type: " << str[newType] << std::endl;
}

void Phaser::addAmmo(AmmoType type)
{
    std::string str[3] = {"regular", "plasma", "rocket"};
    if (this->_loadedAmmo == this->_maxAmmo) {
        std::cout << "Clip full" << std::endl;
    }
    this->_magazine.push_back(str[type]);
}

void Phaser::fire()
{
    std::string sound_to_write;

    if (_loadedAmmo <= Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
    }
    else {
        if (_type == REGULAR)
            sound_to_write = _sound->Regular;
        else if (_type == PLASMA)
            sound_to_write = _sound->Plasma;
        else
            sound_to_write = _sound->Rocket;
        std::cout << sound_to_write << std::endl;
        _magazine.erase(_magazine.begin());
        _loadedAmmo--;
    }
}

int Phaser::getCurrentAmmos()
{
    return (this->_loadedAmmo);
}

void Phaser::ejectClip()
{
    this->_magazine.clear();
    this->_loadedAmmo = 0;
}

void Phaser::reload()
{
    std::vector<std::string> new_vect;
    std::string tab[3] = {"regular", "plasma", "rocket"};

    for (int i = 0; i < _maxAmmo; i++)
        new_vect.push_back(tab[_type]);
    _magazine = new_vect;
    _loadedAmmo = _maxAmmo;
    std::cout << "Reloading..." << std::endl;
}