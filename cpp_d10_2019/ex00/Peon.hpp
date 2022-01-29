/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Peon
*/

#pragma once

#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string name);
		~Peon();
        void getPolymorphed() const override;
	protected:
	private:
};
