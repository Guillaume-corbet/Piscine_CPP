/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** IconveyorBelt
*/

#pragma once

#include "../Box/Wrap.hpp"

class IconveyorBelt {
	public:
		IconveyorBelt();
		~IconveyorBelt();
        virtual void put(Wrap *obj) = 0;
        virtual Wrap *take() = 0;
        virtual void in(Wrap *wrap) = 0;
        virtual void out() = 0;
	protected:
	private:
};