/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** EventManager
*/

#pragma once

#include "Event.hpp"
#include <vector>

class EventManager {
	public:
		EventManager();
        ~EventManager();
        EventManager(EventManager const &other);
        EventManager &operator=(EventManager const &rhs);
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(std::list <Event> &events);
	protected:
	private:
        std::list <Event> _allEvents;
        unsigned int _time;
};