/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ConveyorBeltRand
*/

#pragma once

#include "../Box/Wrap.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "../Box/Box.hpp"
#include "../Box/GiftPaper.hpp"
#include "../Object/LittlePony.hpp"
#include "../Object/Teddy.hpp"

class PapaXmasConveyorBelt;

class ConveyorBeltRand {
	public:
		ConveyorBeltRand();
		~ConveyorBeltRand();
        void randWrap(PapaXmasConveyorBelt *conv);
        void randObject(PapaXmasTable *table);
	protected:
	private:
};