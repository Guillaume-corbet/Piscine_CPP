/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AsteroKreog
*/

#pragma once

#include <string>
#include <iostream>
#include "IAsteroid.hpp"

class AsteroKreog : public IAsteroid {
	public:
		AsteroKreog();
		~AsteroKreog();
        std::string beMined(DeepCoreMiner *miner) const;
        std::string beMined(StripMiner *miner) const;
        std::string getName() const;
	protected:
	private:
};