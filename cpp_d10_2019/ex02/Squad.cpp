/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Squad
*/

#include "Squad.hpp"
#include <iostream>

Squad::Squad()
{

}

Squad::Squad(const Squad &old)
{
    ISpaceMarine *del;
    size_t i = 0;

    while (this->_squad.size() > 0) {
        del = this->_squad.at(0);
        this->_squad.erase(this->_squad.begin());
        del->~ISpaceMarine();
        delete(del);
    }
    while (i < old._squad.size()) {
        del = old._squad.at(i)->clone();
        this->_squad.push_back(del);
        i = i + 1;
    }
}

Squad::~Squad()
{
    ISpaceMarine *del;
    while (this->_squad.size() > 0) {
        del = this->_squad.at(0);
        this->_squad.erase(this->_squad.begin());
        delete(del);
    }
}

int Squad::push(ISpaceMarine *unit)
{
    size_t i = 0;

    if (unit == NULL)
        return (this->_squad.size());
    while (i < this->_squad.size()) {
        if (this->_squad.at(i) == unit)
            return (this->_squad.size());
        i = i + 1;
    }
    this->_squad.push_back(unit);
    return (this->_squad.size());
}

int Squad::getCount() const
{
    return (this->_squad.size());
}

ISpaceMarine *Squad::getUnit(int unit)
{
    size_t nb = unit + 1;

    if (this->_squad.size() < nb) {
        return (NULL);
    }
    return (this->_squad.at(unit));
}