/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr)
{
    this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr()
{
    delete(this->_rawPtr);
}

SimplePtr::SimplePtr(SimplePtr const &ptr)
{

}

SimplePtr &SimplePtr::operator=(SimplePtr const &ptr)
{
    return (*this);
}

BaseComponent *SimplePtr::get() const
{
    return (this->_rawPtr);
}