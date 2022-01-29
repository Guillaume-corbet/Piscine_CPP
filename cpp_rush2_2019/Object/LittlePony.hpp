/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** LittlePony
*/

#pragma once

#include <string>
#include <iostream>
#include "Toy.hpp"

class LittlePony : public Toy
{
	public:
		LittlePony(const std::string &title);
		~LittlePony();
        void isTaken() const override;
	protected:
	private:
};