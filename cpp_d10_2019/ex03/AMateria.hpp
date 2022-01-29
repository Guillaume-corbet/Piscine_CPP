/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AMateria
*/

#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	public:
		AMateria(const std::string &type);
        virtual ~AMateria();
        const std::string &getType() const;
        unsigned int getXP() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
    protected:
        void setXP(int xp);
	private:
        unsigned int xp_;
        const std::string _type;
};
