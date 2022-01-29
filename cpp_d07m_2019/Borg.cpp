/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = Destination::UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weapon_frequency)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = Destination::UNICOMPLEX;
    this->_location = this->_home;
    this->_weaponFrequency = weapon_frequency;
    this->_shield = 100;
    this->_repair = 3;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weapon_frequency, short repair)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = Destination::UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    this->_weaponFrequency = weapon_frequency;
    this->_repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{

}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield()
{
    return (this->_shield);
}

int Borg::Ship::getRepair()
{
    return (this->_repair);
}

int Borg::Ship::getWeaponFrequency()
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;

}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair = this->_repair - 1;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}