/*
** EPITECH PROJECT, 2020
** day6
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(int id);
		~KoalaNurse();
        void giveDrug(std::string Drug, SickKoala *koala);
        std::string readReport(std::string filename);
		void timeCheck();
		int getID();
	private:
        int id;
		bool working_status;
};

#endif /* !KOALANURSE_HPP_ */
