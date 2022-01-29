/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "SickKoala.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string name);
		~KoalaDoctor();
        void diagnose(SickKoala *patient);
        void timeCheck();
        std::string getName();
	private:
        std::string name;
        bool working_status;
};

#endif /* !KOALADOCTOR_HPP_ */
