/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** DeepCoreMiner
*/

#pragma once

#include "IAsteroid.hpp"
#include <string>
#include <iostream>
#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {
	public:
		DeepCoreMiner();
		~DeepCoreMiner();
        void mine(IAsteroid *asteroid);
	protected:
	private:
};