/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasConveyorBelt
*/

#pragma once

#include "IconveyorBelt.hpp"
#include "ConveyorBeltRand.hpp"

class PapaXmasConveyorBelt : public IconveyorBelt
{
	public:
        enum side {LEFT, RIGHT};
		PapaXmasConveyorBelt();
		~PapaXmasConveyorBelt();
        void put(Wrap *wrap) override;
        Wrap *take() override;
        void getInputObject();
        void pushOutputObject();
        void in(Wrap *wrap);
        void out();
        Wrap *getWrap();
	protected:
	private:
        Wrap *_wrap;
};