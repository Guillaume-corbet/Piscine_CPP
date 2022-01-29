/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#pragma once

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
	public:
		FruitBox(int size);
		~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;
        int getSize() const;
	protected:
	private:
        FruitNode *_head;
        int _size;
};