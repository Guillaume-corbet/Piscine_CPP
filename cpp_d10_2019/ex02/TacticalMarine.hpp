/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TacticalMarine
*/

#pragma once

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		~TacticalMarine() override;
        ISpaceMarine *clone() const override;
        void battleCry() const override;
        void rangedAttack() const override;
        void meleeAttack() const override;
	protected:
	private:
};
