/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** IELF
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "../Object/Object.hpp"
#include "Hand.hpp"
#include "../Carpet/PapaXmasConveyorBelt.hpp"

class IElf {
	public:
		IElf();
		~IElf();
		virtual std::vector<std::string> look() = 0;
		virtual void take(PapaXmasConveyorBelt::side side) = 0;
		virtual void put(PapaXmasConveyorBelt::side side) = 0;
		virtual void takeObject(PapaXmasConveyorBelt::side side, int idx) = 0;

	protected:
	private:
};

#endif /* !IELF_HPP_ */