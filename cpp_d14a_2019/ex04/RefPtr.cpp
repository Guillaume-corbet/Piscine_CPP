/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr()
{
    this->_rawPtr = NULL;
}

RefPtr::RefPtr(BaseComponent *rawPtr)
{
    this->_rawPtr = rawPtr;
}

RefPtr::~RefPtr()
{
}

RefPtr::RefPtr(RefPtr const &other)
{
    this->_rawPtr = other._rawPtr;
}

BaseComponent *RefPtr::get() const
{
    return (this->_rawPtr);
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    this->_rawPtr = other._rawPtr;
    return (*this);
}