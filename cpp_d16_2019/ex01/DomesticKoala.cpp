/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action)
{
    this->_action = &action;
    this->_command = new std::vector<unsigned char>;
    this->_methode = new std::vector<DomesticKoala::methodPointer_t>;
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &old)
{
    this->_action = old._action;
    this->_command = old._command;
    this->_methode = old._methode;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &old)
{
    this->_action = old._action;
    this->_command = old._command;
    this->_methode = old._methode;
    return (*this);
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const
{
    return (this->_methode);
}

void DomesticKoala::learnAction(unsigned char command, DomesticKoala::methodPointer_t action)
{
    size_t i = 0;

    while (this->_command != NULL && this->_command->size() > i) {
        if (this->_command->at(i) == command)
            return;
        i = i + 1;
    }
    this->_command->push_back(command);
    this->_methode->push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    size_t i = 0;

    while (this->_command != NULL && this->_command->size() > i && this->_command->at(i) != command)
        i = i + 1;
    if (this->_command != NULL && this->_command->size() > i && this->_command->at(i) == command) {
        this->_command->erase(this->_command->begin() + i);
        this->_methode->erase(this->_methode->begin() + i);
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    size_t i = 0;
    methodPointer_t action;

    while (this->_command != NULL && this->_command->size() > i && this->_command->at(i) != command)
        i = i + 1;
    if (this->_command != NULL && this->_command->size() > i && this->_command->at(i) == command) {
        action = this->_methode->at(i);
        __invoke(action, _action, param);
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    this->_action = &action;
}