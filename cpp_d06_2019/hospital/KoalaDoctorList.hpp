/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include <string>
#include <iostream>
#include "KoalaDoctor.hpp"

class KoalaDoctorList {
	public:
		KoalaDoctorList(KoalaDoctor *doctor);
		~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *next);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *doctorList);
        KoalaDoctorList *removeFromName(std::string name);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void dump();
	protected:
	private:
        KoalaDoctor *doctor;
        KoalaDoctorList *next;
};

#endif /* !KOALADOCTORLIST_HPP_ */
