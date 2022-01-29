/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** StripMiner
*/

#pragma once

#include "IAsteroid.hpp"
#include <string>
#include <iostream>
#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {
	public:
		StripMiner();
		~StripMiner();
        void mine(IAsteroid *asteroid);
	protected:
	private:
};
