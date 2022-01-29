/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
    this->_time = 0;
    this->_event = "";
}

Event::~Event()
{
}

Event::Event(unsigned int time, const std::string &event)
{
    this->_event = event;
    this->_time = time;
}

Event::Event(const Event &other)
{
    this->_event = other._event;
    this->_time = other._time;
}

Event &Event::operator=(const Event &rhs)
{
    this->_time = rhs._time;
    this->_event = rhs._event;
    return (*this);
}

unsigned int Event::getTime() const
{
    return (this->_time);
}

const std::string &Event::getEvent() const
{
    return (this->_event);
}

void Event::setTime(unsigned int time)
{
    this->_time = time;
}

void Event::setEvent(const std::string &event)
{
    this->_event = event;
}