/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** MateriaSource
*/

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{

}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (this->materia.size() < 4)
        this->materia.push_back(materia);
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    AMateria *mat;
    size_t i = 0;

    while (i < this->materia.size()) {
        if (this->materia.at(i)->getType() == type) {
            if (type == "ice") {
                mat = new Ice();
                return (mat);
            } else if (type == "cure") {
                mat = new Cure();
                return (mat);
            } else {
                return (NULL);
            }
        }
        i = i + 1;
    }
    return (NULL);
}