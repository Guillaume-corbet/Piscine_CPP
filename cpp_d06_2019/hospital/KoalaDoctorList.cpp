/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
    this->doctor = doctor;
    this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{

}

bool KoalaDoctorList::isEnd()
{
    if (this->next == NULL)
        return (true);
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *next)
{
    KoalaDoctorList *tmp = this;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = next;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    while (tmp->next != NULL) {
        if (name.compare(tmp->doctor->getName()) == 0)
            return (tmp->doctor);
        tmp = tmp->next;
    }
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *patienList)
{
    KoalaDoctorList *tmp = this;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *tmp = this;
    KoalaDoctorList *remove;

    if (name.compare(this->doctor->getName())) {
        remove = this->next;
        this->~KoalaDoctorList();
        return (remove);
    }
    while (tmp->next != NULL) {
        if (name.compare(this->next->doctor->getName())) {
            remove = tmp->next;
            tmp->next = tmp->next->next;
            remove->~KoalaDoctorList();
            return (this);
        }
        tmp = tmp->next;
    }
    return (this);
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->doctor);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return (this->next);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp;

    if (this->doctor != nullptr)
        std::cout << "Doctors: " << this->doctor->getName();
    else 
        std::cout << "Doctors: " << "nullptr";
    tmp = this->next;
    while (tmp != NULL) {
        if (tmp->doctor != nullptr)
            std::cout << ", " << tmp->doctor->getName();
        else
            std::cout << ", " << "nullptr";
        tmp = tmp->next;
    }
    std::cout << "." << std::endl;
}