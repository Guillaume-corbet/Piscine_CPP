/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Hunter
*/

#pragma once

#include "Warrior.hpp"

class Hunter : public Warrior
{
	public:
		Hunter(const std::string &name, int level);
		~Hunter();
        using Warrior::CloseAttack;
        using Warrior::Heal;
        int RangeAttack();
        void RestorePower();
	private:
};