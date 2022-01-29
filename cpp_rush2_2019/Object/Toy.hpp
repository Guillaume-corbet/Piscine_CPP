/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Toy
*/

#pragma once

#include <string>
#include <iostream>
#include "Object.hpp"

class Toy : public Object
{
	public:
		Toy(const std::string &title);
		~Toy();
        void isTaken() const override;
	protected:
	private:
};
