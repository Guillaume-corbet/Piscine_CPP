/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Buzz
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(std::string name, std::string filename = "buzz.txt");
		~Buzz();
        void speak(std::string say) override;
	protected:
	private:
};