/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Event
*/

#pragma once

#include <string>
#include <iostream>
#include <list>

class Event {
	public:
		Event();
        Event(unsigned int time, const std::string &event);
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        unsigned int getTime() const;
        const std::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(const std::string &event);
	protected:
	private:
        std::string _event;
        unsigned int _time;
};