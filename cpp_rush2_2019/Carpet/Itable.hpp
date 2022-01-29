/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Itable
*/

#pragma once

#include "../Object/Object.hpp"
#include <vector>

class Itable {
	public:
		Itable();
		~Itable();
        virtual void put(Object *obj) = 0;
        virtual Object *take(int pos) = 0;
        virtual std::vector<std::string> look() = 0;
	protected:
	private:
};