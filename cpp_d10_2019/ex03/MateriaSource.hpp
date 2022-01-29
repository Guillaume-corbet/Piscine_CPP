/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** MateriaSource
*/

#pragma once

#include "IMateriaSource.hpp"
#include <vector>
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		~MateriaSource();
        void learnMateria(AMateria *materia);
        AMateria *createMateria(const std::string &type);
	private:
        std::vector<AMateria *> materia;
};