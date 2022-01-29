/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitNode
*/

#pragma once

#include "Fruit.hpp"

class FruitNode {
	public:
		FruitNode(Fruit *f, FruitNode *next) {this->f = f; this->next = next;};
		~FruitNode();
        FruitNode *getNext() const {return (this->next);};
        Fruit *getFruit() const {return (this->f);};
        void setNext(FruitNode *next) {this->next = next;}
        Fruit *f;
        FruitNode *next;
	protected:
	private:
};