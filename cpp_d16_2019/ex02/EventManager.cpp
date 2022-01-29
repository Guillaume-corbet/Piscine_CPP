/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager()
{
    this->_time = 0;
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager const &other)
{
    this->_allEvents = other._allEvents;
    this->_time = other._time;
}

EventManager &EventManager::operator=(const EventManager &rhs)
{
    this->_allEvents = rhs._allEvents;
    this->_time = rhs._time;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    auto it = this->_allEvents.begin();
    size_t i = 0;

    if (e.getTime() < this->_time)
        return;
    while (i < this->_allEvents.size() && it->getTime() <= e.getTime()) {
        std::advance(it, 1);
        i = i + 1;
    }
    std::prev(it, 1);
    this->_allEvents.insert(it, e);
}

void EventManager::removeEventsAt(unsigned int time)
{
    auto it = this->_allEvents.begin();
    size_t i = 0;

    while (i < this->_allEvents.size()) {
        if (it->getTime() == time) {
            this->_allEvents.erase(it);
            removeEventsAt(time);
        }
        std::advance(it, 1);
        i = i + 1;
    }
}

void EventManager::dumpEvents() const
{
    auto it = this->_allEvents.begin();
    size_t i = 0;

    while (i < this->_allEvents.size()) {
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        std::advance(it, 1);
        i = i + 1;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    auto it = this->_allEvents.begin();
    size_t i = 0;

    while (i < this->_allEvents.size()) {
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        std::advance(it, 1);
        i = i + 1;
    }
}

void EventManager::addTime(unsigned int time)
{
    unsigned int new_time = this->_time + time;
    auto it = this->_allEvents.begin();
    size_t i = 0;

    while (i < this->_allEvents.size() && it->getTime() <= new_time) {
        if (it->getTime() <= new_time) {
            std::cout << it->getEvent() << std::endl;
        }
        std::advance(it, 1);
        i = i + 1;
    }
    std::prev(it, 1);
    this->_allEvents.erase(this->_allEvents.begin(), it);
    this->_time = new_time;
}

void EventManager::addEventList(std::list <Event> &events)
{
    auto it = events.begin();

    while (it != events.end() && events.size() > 0) {
        this->addEvent(events.front());
        events.erase(events.begin());
    }
}