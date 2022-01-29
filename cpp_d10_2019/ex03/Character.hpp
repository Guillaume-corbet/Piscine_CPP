/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character
*/

#pragma once

#include "ICharacter.hpp"
#include <vector>
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character(const std::string &name);
        Character(const Character &old);
		~Character();
        const std::string &getName()  const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
	protected:
	private:
        std::vector<AMateria *> materia;
        const std::string name;
};