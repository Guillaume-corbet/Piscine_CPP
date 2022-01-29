/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap():Object("Wrap", "wrap"), _object(NULL), _isOpen(true)
{
}

Wrap::~Wrap()
{
}

void Wrap::openMe()
{
    _isOpen = true;
}

void Wrap::closeMe()
{
    _isOpen = false;
}

void Wrap::wrapMeThat(const Object *obj)
{
    if (_isOpen && !_object) {
        _object = obj;
    }
}

bool Wrap::isOpen()
{
    return (_isOpen);
}

bool Wrap::isFull()
{
    if (_object)
        return (true);
    return (false);
}

const Object *Wrap::getObject()
{
    return (_object);
}

void Wrap::setObject(const Object *obj)
{
    if (!_object)
        _object = obj;
    else
        std::cerr << "There is already a " << getObject()->getTitle() << " in the wrap!" << std::endl;
}

Wrap &Wrap::operator=(const Wrap &cur)
{
    this->_object = cur._object;
    this->_isOpen = cur._isOpen;
    return (*this);
}