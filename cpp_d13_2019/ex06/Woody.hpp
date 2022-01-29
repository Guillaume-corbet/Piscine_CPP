/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Woody
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy {
	public:
		Woody(std::string name, std::string filename = "woody.txt");
		~Woody();
        bool speak(std::string say) override;
	protected:
	private:
};