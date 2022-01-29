/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial):m_serial(serial), _x(x), _y(y)
{
    this->_ptr = NULL;
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::removeCom()
{
    KreogCom *sto;
 
    if (!this->_ptr)
        return;
    if (!this->_ptr->_ptr) {
        delete(this->_ptr);
        this->_ptr = NULL;
    } else {
        sto = this->_ptr->_ptr;
        delete(this->_ptr);
        this->_ptr = sto;
    }
}

KreogCom *KreogCom::getCom()
{
    return (this->_ptr);
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);
 
    if (!this->_ptr) {
        this->_ptr = newCom;
    } else {
        newCom->_ptr = this->_ptr;
        this->_ptr = newCom;
    }
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->_ptr;

    while (tmp != NULL) {
        tmp->ping();
        tmp = tmp->getCom();
    }
    this->ping();
}