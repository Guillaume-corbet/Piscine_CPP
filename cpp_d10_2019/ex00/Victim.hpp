/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Victim
*/

#pragma once

#include <string>
#include <iostream>

class Victim {
	public:
		Victim(std::string name);
		~Victim();
        std::string getName() const;
        void setName(std::string name);
        virtual void getPolymorphed() const;
	protected:
	private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &s, const Victim &tmp);
