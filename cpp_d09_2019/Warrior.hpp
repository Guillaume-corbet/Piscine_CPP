/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Warrior
*/

#pragma once

#include "Character.hpp"

class Warrior : virtual public Character
{
	public:
		Warrior(const std::string &name, int level);
		~Warrior();
        int CloseAttack();
        int RangeAttack();
	protected:
        Warrior(const std::string &name, int level, std::string weapon,int stamina, int spirit, int agility, int strength, int intelligence);
	private:
        std::string weaponName;
};