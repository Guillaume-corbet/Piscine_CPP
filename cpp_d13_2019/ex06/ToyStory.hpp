/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** ToyStory
*/

#pragma once

#include "Toy.hpp"
#include <vector>

class ToyStory {
	public:
		ToyStory();
		~ToyStory();
        static void tellMeAStory(std::string filename, Toy toy1,  bool(Toy::*func1)(std::string say), Toy toy2, bool(Toy::*func2)(std::string say));
	protected:
	private:
};