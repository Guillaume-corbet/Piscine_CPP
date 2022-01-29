/*
** EPITECH PROJECT, 2020
** day6
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>
#include <iostream>

class SickKoala {
	public:
        SickKoala(std::string name);
		~SickKoala();
        void poke();
        bool takeDrug(std::string str);
        void overDrive(std::string str);
		std::string getName();
	private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
