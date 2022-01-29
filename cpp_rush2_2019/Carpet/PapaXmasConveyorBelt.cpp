/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasConveyorBelt
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

void PapaXmasConveyorBelt::put(Wrap *wrap)
{
    if (_wrap != NULL) {
        std::cerr << "ConveyorBelt have already a wrap" << std::endl;
        return;
    }
    _wrap = wrap;
}

Wrap *PapaXmasConveyorBelt::take()
{
    Wrap *wrap = this->_wrap;
    this->_wrap = NULL;
    return (wrap);
}

void PapaXmasConveyorBelt::out()
{
    if (!this->_wrap->isFull()) {
        std::cerr << "No object on the wrap" << std::endl;
        return;
    }
    _wrap = NULL;
}

void PapaXmasConveyorBelt::in(Wrap *wrap)
{
    if (_wrap != NULL) {
        std::cerr << "ConveyorBelt have already a wrap" << std::endl;
        return;
    }
    this->_wrap = wrap;
}

void PapaXmasConveyorBelt::getInputObject()
{
    ConveyorBeltRand rand = ConveyorBeltRand();

    rand.randWrap(this);
    std::cout << "e speex'n'XML" << std::endl;
}

void PapaXmasConveyorBelt::pushOutputObject()
{
    std::cout << "BUTTON OUT" << std::endl;
}

Wrap *PapaXmasConveyorBelt::getWrap()
{
    return (this->_wrap);
}