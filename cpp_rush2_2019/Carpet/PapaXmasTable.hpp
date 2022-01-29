/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasTable
*/

#pragma once

#include "Itable.hpp"
#include <vector>

class PapaXmasTable : public Itable
{
	public:
		PapaXmasTable();
		~PapaXmasTable();
        void put(Object *obj) override;
        Object *take(int pos);
        Object *lookObj(int pos);
        std::vector<std::string> look() override;
	protected:
	private:
        std::vector<Object *> obj;
};