/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Ice
*/

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
        AMateria *clone() const override;
        void use(ICharacter &target) override;
	private:
};
