/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
}

PapaXmasTable::~PapaXmasTable()
{
}

void PapaXmasTable::put(Object *obj)
{
    if (this->obj.size() > 9) {
        std::cerr << "Object : " << obj->getTitle() << " fall of the table" << std::endl;
        obj->~Object();
    }
    this->obj.push_back(obj);
    
}

Object *PapaXmasTable::take(int pos)
{
    Object *tak;
    if (this->obj.size() < (size_t)pos) {
        std::cerr << "No object on table" << std::endl;
        return NULL;
    }
    tak = this->obj.at(pos);
    this->obj.erase(this->obj.begin() + pos);
    return (tak);
}

Object *PapaXmasTable::lookObj(int pos)
{
    if (this->obj.size() == 0)
        return (NULL);
    if (this->obj.size() - 1 < (size_t)pos) {
        return NULL;
    }
    return (this->obj.at(pos));
}

std::vector<std::string> PapaXmasTable::look()
{
    std::vector<std::string>arr;
    int i = 0;

    if (obj.size() == 0) {
        std::cout << "No object on Table" << std::endl;
        return (arr);
    }
    while ((size_t)i < obj.size()) {
        if (this->obj.at(i) == 0 && this->obj.at(i)->getType() != "object") {
            arr.push_back("box");
        } else
            arr.push_back(this->obj.at(i)->getTitle());
        i = i + 1;
    }
    return (arr);
}