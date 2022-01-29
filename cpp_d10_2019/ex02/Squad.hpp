/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Squad
*/

#pragma once

#include "ISquad.hpp"
#include <vector>

class Squad : public ISquad
{
	public:
		Squad();
        Squad(const Squad &old);
		~Squad();
        int getCount() const override;
        ISpaceMarine *getUnit(int unit) override;
        int push(ISpaceMarine *unit) override;
	private:
        std::vector<ISpaceMarine *> _squad;
};