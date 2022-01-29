/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** MiningBarge
*/

#pragma once

#include "IAsteroid.hpp"
#include <vector>

class MiningBarge {
	public:
		MiningBarge();
		~MiningBarge();
        void equip(IMiningLaser *laser);
        void mine(IAsteroid *asteroid) const;
	protected:
	private:
        std::vector<IMiningLaser *> laser;
};