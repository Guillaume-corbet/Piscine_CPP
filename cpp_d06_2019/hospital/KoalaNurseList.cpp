/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
    this->nurse = nurse;
    this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{

}

bool KoalaNurseList::isEnd()
{
    if (this->next == NULL)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *next)
{
    KoalaNurseList *tmp = this;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = next;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this;

    while (tmp->next != NULL) {
        if (id == tmp->nurse->getID())
            return (tmp->nurse);
        tmp = tmp->next;
    }
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *nurseList)
{
    KoalaNurseList *tmp = this;

    if (this == nurseList) {
        return (this->next);
    }
    while (tmp->next != NULL) {
        if (tmp->next == nurseList) {
            tmp->next = tmp->next->next;
            return (this);
        }
        tmp = tmp->next;
    }
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *tmp = this;
    KoalaNurseList *remove;

    if (id == this->nurse->getID()) {
        remove = this->next;
        this->~KoalaNurseList();
        return (remove);
    }
    while (tmp->next != NULL) {
        if (id == this->next->nurse->getID()) {
            remove = tmp->next;
            tmp->next = tmp->next->next;
            remove->~KoalaNurseList();
            return (this);
        }
        tmp = tmp->next;
    }
    return (this);
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->nurse);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (this->next);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp;

    if (this->nurse != nullptr)
        std::cout << "Nurses: " << this->nurse->getID();
    else 
        std::cout << "Nurses: " << "nullptr";
    tmp = this->next;
    while (tmp != NULL) {
        if (tmp->nurse != nullptr)
            std::cout << ", " << tmp->nurse->getID();
        else
            std::cout << ", " << "nullptr";
        tmp = tmp->next;
    }
    std::cout << "." << std::endl;
}