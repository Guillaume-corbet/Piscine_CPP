
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
    if (_water == 0)
        throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer");
    _started = true;
}

void
WaterReclaimer::useWater(int water)
{
    if (water < 0)
        throw UserError("Water use should be positif.", "WaterReclaimer");
    if (this->_started == false) {
        throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
    }
    _water -= water;
    if (_water < 10) {
        _water += water;
        throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    }
}

void
WaterReclaimer::generateWater()
{
    _water += 10;
    if (_water > 100) {
        _water -= 10;
        throw NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer");
    }
}
