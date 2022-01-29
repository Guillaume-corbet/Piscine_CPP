/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <string>
#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral
        {
            public:
                Admiral(std::string name);
                ~Admiral();
                bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *target);
                void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
                bool move(Federation::Starfleet::Ship *ship, Destination dest);
            private:
                std::string _name;
        };
    }
}

#endif /* !ADMIRAL_HPP_ */
