/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>
#include <iostream>

class Arms {
	public:
		Arms(std::string const &serial = "A-01", bool functional = true);
		~Arms();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
	private:
        std::string _serial;
        bool _functional;
};

class Legs {
	public:
		Legs(std::string const &serial = "L-01", bool functional = true);
		~Legs();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
	private:
        std::string _serial;
        bool _functional;
};

class Head {
	public:
		Head(std::string const &serial = "H-01", bool functional = true);
		~Head();
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
	private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
