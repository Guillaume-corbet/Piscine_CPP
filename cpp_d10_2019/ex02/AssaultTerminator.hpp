/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AssaultTerminator
*/

#pragma once

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator();
		~AssaultTerminator() override;
        ISpaceMarine *clone() const override;
        void battleCry() const override;
        void rangedAttack() const override;
        void meleeAttack() const override;
        void test() const;
	protected:
	private:
};
