/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include <string>
#include <iostream>
#include "KoalaNurse.hpp"

class KoalaNurseList {
	public:
		KoalaNurseList(KoalaNurse *nurse);
		~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *next);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *NurseList);
        KoalaNurseList *removeFromID(int id);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        void dump();
	protected:
	private:
        KoalaNurse *nurse;
        KoalaNurseList *next;
};

#endif /* !KOALANURSELIST_HPP_ */
