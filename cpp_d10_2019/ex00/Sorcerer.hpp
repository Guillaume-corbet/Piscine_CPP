/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Sorcerer
*/

#pragma once

#include <string>
#include <iostream>

#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer();
        std::string getName() const;
        std::string getTitle() const;
        void setName(std::string name);
        void setTitle(std::string title);
        void polymorph(const Victim &victim) const;
	protected:
	private:
        std::string _name;
        std::string _title;

};

std::ostream &operator<<(std::ostream &s, const Sorcerer &tmp);
