/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** DomesticKoala
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "KoalaAction.hpp"
#include <functional>

class DomesticKoala {
	public:
		DomesticKoala(KoalaAction &);
        ~DomesticKoala ();
        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);
        using methodPointer_t = void(KoalaAction::*)(const std::string &param);
        const std::vector <methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);
	protected:
	private:
        std::vector<methodPointer_t> *_methode;
        std::vector<unsigned char> *_command;
        KoalaAction *_action;
};