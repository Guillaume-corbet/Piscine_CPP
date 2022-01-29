/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP_
#define PAPAXMASELF_HPP_

#include <typeinfo>
#include "../Object/Object.hpp"
#include "Hand.hpp"
#include "IElf.hpp"
#include "../Carpet/PapaXmasConveyorBelt.hpp"
#include "../Carpet/PapaXmasTable.hpp"
#include "../Carpet/ConveyorBeltRand.hpp"

class PapaXmasElf: public IElf {
	public:
		PapaXmasElf(PapaXmasTable *table, PapaXmasConveyorBelt *belt);
		~PapaXmasElf();
        std::vector<std::string> look();
		void take(PapaXmasConveyorBelt::side side);
		void put(PapaXmasConveyorBelt::side side);
		void takeObject(PapaXmasConveyorBelt::side side, int idx);
        void putObject(PapaXmasConveyorBelt::side side);
        bool canWrap();
        bool checkHands(const std::string id);
        Object *checkRetHands(const std::string id);
        void createAGift();
        Object *getObjectByType(const std::string type);

	protected:
	private:
        Hand _left;
		Hand _right;
        PapaXmasTable *_table;
        PapaXmasConveyorBelt *_belt;
};

#endif /* !PAPAXMASELF_HPP_ */