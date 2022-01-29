/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Mage
*/

#pragma once

#include "Character.hpp"

class Mage : virtual public Character
{
	public:
		Mage(const std::string &name, int level);
		~Mage();
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
	protected:
        Mage(const std::string &name, int level, int Stamina, int Spirit, int Agility, int strength, int intelligence);
	private:
};