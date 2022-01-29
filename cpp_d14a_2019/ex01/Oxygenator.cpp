
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    _quantity -= quantity;
    if (_quantity == 10) {
        _quantity += quantity;
        throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
    }
    if (_quantity < 10) {
        _quantity += quantity;
        throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
    }
}
