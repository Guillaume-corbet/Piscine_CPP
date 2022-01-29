/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper():Wrap()
{
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(const Object *obj)
{
    if (!isFull()) {
        setObject(obj);
    }
    else {
        std::cerr << "There is already a " << getObject()->getTitle() << " in the giftpaper!" << std::endl;
    }
}