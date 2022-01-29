/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Federation
*/

#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = Destination::EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = Destination::EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    this->_name = "Entreprise";
    this->_length = 289;
    this->_width = 132;
    this->_maxWarp = 6;
    this->_home = Destination::EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = 0;
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << this->_name << ": The core is ";
    if (this->_core->checkReactor()->isStable())
        std::cout << "stable at the time." << std::endl;
    else
        std::cout << "unstable at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    this->captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (this->_photonTorpedo <= 0) {
        std::cout << this->_name << ": No enough torpedo to fire, " << this->captain->getName() << "!" << std::endl;
        return;
    }
    this->_photonTorpedo = this->_photonTorpedo - 1;
    target->setShield(target->getShield() - 50);
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    if (this->_photonTorpedo <= 0) {
        std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (this->_photonTorpedo < torpedoes) {
        std::cout << this->_name << ": No enough torpedo to fire, " << this->captain->getName() << "!" << std::endl;
        return;
    }
    this->_photonTorpedo = this->_photonTorpedo - torpedoes;
    target->setShield(target->getShield() - (50 * torpedoes));
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    if (this->_photonTorpedo <= 0) {
        std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
    }
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{

}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = Destination::VULCAN;
    this->_location = this->_home;
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << this->_name << ": The core is ";
    if (this->_core->checkReactor()->isStable())
        std::cout << "stable at the time." << std::endl;
    else
        std::cout << "unstable at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (this->_core);
}
