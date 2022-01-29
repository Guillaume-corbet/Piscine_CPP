/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Hand
*/

#ifndef HAND_HPP_
#define HAND_HPP_

#include "../Object/Object.hpp"
#include "../Carpet/PapaXmasConveyorBelt.hpp"

class Hand {
	public:
		Hand(PapaXmasConveyorBelt::side side);
		~Hand();
        void pushInButton(PapaXmasConveyorBelt *ptr);
        void pushOutButton(PapaXmasConveyorBelt *ptr);
        bool isEmpty();
        Object *getObject();
        void setObject(Object *obj);
        void crack();
        void reset();

	protected:
	private:
        Object *_obj;
        PapaXmasConveyorBelt::side _side;
};

#endif /* !HAND_HPP_ */