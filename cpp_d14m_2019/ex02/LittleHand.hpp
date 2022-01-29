/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** LittleHand
*/

#pragma once

#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
    protected:
	private:
};