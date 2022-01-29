/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Paladin
*/

#pragma once

#include "Warrior.hpp"
#include "Priest.hpp"
#include "Character.hpp"

class Paladin : public Warrior, public Priest
{
	public:
		Paladin(const std::string &name, int level);
		~Paladin();
        int Intercept();
        using Priest::Heal;
        using Priest::RangeAttack;
        using Warrior::CloseAttack;
        using Warrior::RestorePower;
	protected:
	private:
};