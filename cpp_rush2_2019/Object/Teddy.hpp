/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Teddy
*/

#pragma once

#include "Toy.hpp"
#include <string>
#include <iostream>

class Teddy : public Toy
{
	public:
		Teddy(const std::string &title);
		~Teddy();
        void isTaken() const override;
	protected:
	private:
};