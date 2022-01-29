/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient)
{
    this->patient = patient;
    this->next = NULL;
}

SickKoalaList::~SickKoalaList()
{

}

bool SickKoalaList::isEnd()
{
    if (this->next == NULL)
        return (true);
    return (false);
}

void SickKoalaList::append(SickKoalaList *next)
{
    SickKoalaList *tmp = this;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = next;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this;

    while (tmp->next != NULL) {
        if (name.compare(tmp->patient->getName()) == 0)
            return (tmp->patient);
        tmp = tmp->next;
    }
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *patienList)
{
    SickKoalaList *tmp = this;

    if (this == patienList) {
        return (this->next);
    }
    while (tmp->next != NULL) {
        if (tmp->next == patienList) {
            tmp->next = tmp->next->next;
            return (this);
        }
        tmp = tmp->next;
    }
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *tmp = this;
    SickKoalaList *remove;

    if (name.compare(this->patient->getName())) {
        remove = this->next;
        this->~SickKoalaList();
        return (remove);
    }
    while (tmp->next != NULL) {
        if (name.compare(this->next->patient->getName())) {
            remove = tmp->next;
            tmp->next = tmp->next->next;
            remove->~SickKoalaList();
            return (this);
        }
        tmp = tmp->next;
    }
    return (this);
}

SickKoala *SickKoalaList::getContent()
{
    return (this->patient);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->next);
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp;

    if (this->patient != nullptr)
        std::cout << "Patients: " << this->patient->getName();
    else 
        std::cout << "Patients: " << "nullptr";
    tmp = this->next;
    while (tmp != NULL) {
        if (tmp->patient != nullptr)
            std::cout << ", " << tmp->patient->getName();
        else
            std::cout << ", " << "nullptr";
        tmp = tmp->next;
    }
    std::cout << "." << std::endl;
}