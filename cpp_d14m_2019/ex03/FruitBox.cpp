/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->_head = NULL;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = this->_head;
    int size = 0;
    
    while (tmp) {
        size = size + 1;
        tmp = tmp->getNext();
    }
    return (size);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = this->_head;
    if (this->nbFruits() >= this->_size)
        return (false);
    if (this->_head == NULL) {
        FruitNode *ne = new FruitNode(f, NULL);
        this->_head = ne;
        return (true);
    }
    while (tmp->getNext()) {
        if (tmp->getFruit() == f)
            return (false);
        tmp = tmp->getNext();
    }
    FruitNode *ne = new FruitNode(f, NULL);
    tmp->setNext(ne);
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmp = this->_head;
    FruitNode *ne;
    
    if (this->nbFruits() == 0) {
        return (nullptr);
    }
    while (tmp) {
        if (tmp->getFruit() != NULL) {
            ne = tmp->getNext();
            this->_head = ne;
            return (tmp->getFruit());
        }
    }
    return (nullptr);
}

FruitNode *FruitBox::head() const
{
    return (this->_head);
}

int FruitBox::getSize() const
{
    return (this->_size);
}