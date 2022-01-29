
#include <cmath>
#include "Errors.hpp"
#include "Engine.hpp"
#include <iostream>

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power),
      _x(x),
      _y(y)
{
}

Engine::~Engine()
{
}

void
Engine::goTorward(float x, float y)
{
    if (distanceTo(x, y) > _power) {
        std::string str_x = std::to_string(x);
        while (str_x.at(str_x.size() - 1) == '0') {
            str_x.erase(str_x.size() - 1);
        }
        if (str_x.at(str_x.size() - 1) == '.')
            str_x.erase(str_x.size() - 1);
        std::string str_y = std::to_string(y);
        while (str_y.at(str_y.size() - 1) == '0') {
            str_y.erase(str_y.size() - 1);
        }
        if (str_y.at(str_y.size() - 1) == '.')
            str_y.erase(str_y.size() - 1);
        std::string str = "Cannot reach destination (" + str_x + ", " + str_y + ").";
        throw UserError(str, "Engine");
    }
    _x = x;
    _y = y;
}

float
Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float
Engine::getX() const
{
    return _x;
}

float
Engine::getY() const
{
    return _y;
}

