/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title, const std::string &type):_title(title), _into(NULL), _type(type)
{
    //std::cout << "Object Ctor" << std::endl;
}

Object::~Object()
{
    //std::cout << "Object Dtor" << std::endl;
}

const std::string Object::getTitle() const
{
    if (_type != "object")
        return ("Wrap");
    return (this->_title);
}

void Object::isTaken() const
{
    //std::cout << "Object taken" << std::endl;
}

void Object::setObject(Object *ptr)
{
    _into = ptr;
}

void Object::setType(const std::string &type)
{
    this->_type = type;
}

std::string Object::getType()
{
    return (this->_type);
}