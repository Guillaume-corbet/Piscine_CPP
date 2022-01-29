/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Hand
*/

#include "Hand.hpp"

Hand::Hand(PapaXmasConveyorBelt::side side):_obj(NULL), _side(side)
{
}

Hand::~Hand()
{
}

void Hand::pushInButton(PapaXmasConveyorBelt *ptr)
{
    if (isEmpty()) {
        ptr->getInputObject();
    }
    else {
        std::cerr << _side << " hand already carry an object" << std::endl;
    }
}

void Hand::pushOutButton(PapaXmasConveyorBelt *ptr)
{
    if (isEmpty()) {
        ptr->pushOutputObject();
    }
    else {
        std::cerr << _side << " hand already carry an object" << std::endl;
    }
}

bool Hand::isEmpty()
{
    if (_obj)
        return (false);
    return (true);
}

Object *Hand::getObject()
{
    if (!_obj)
        return (NULL);
    return (_obj);
}

void Hand::setObject(Object *obj)
{
    if (_obj) {
        std::cerr << _side << " hand already carry an object" << std::endl;
    }
    else {
        //new_obj = new Object("Wrap", "wrap");
        _obj = obj;
    }
}

void Hand::reset()
{
    _obj = NULL;
}

void Hand::crack()
{
    std::cout << "* Crack *" << std::endl;
}