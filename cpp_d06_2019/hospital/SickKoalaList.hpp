/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include <string>
#include <iostream>
#include "SickKoala.hpp"

class SickKoalaList {
	public:
		SickKoalaList(SickKoala *patient);
		~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *next);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *patientList);
        SickKoalaList *removeFromName(std::string name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
	private:
        SickKoala *patient;
        SickKoalaList *next;
};

#endif /* !SICKKOALALIST_HPP_ */
