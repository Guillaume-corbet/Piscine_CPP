/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Cure
*/

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
        AMateria *clone() const override;
        void use(ICharacter &target) override;
	protected:
	private:
};