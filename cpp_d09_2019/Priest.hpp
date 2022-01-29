/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Priest
*/

#pragma once

#include "Mage.hpp"

class Priest : public Mage
{
	public:
		Priest(const std::string &name, int level);
		~Priest();
        int CloseAttack();
        void Heal();
	protected:
        Priest(const std::string &name, int level, int stamina, int spirit, int agility, int strength, int intelligence);
	private:
};