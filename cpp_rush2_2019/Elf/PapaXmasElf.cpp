/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf(PapaXmasTable *table, PapaXmasConveyorBelt *belt):
_left(Hand(PapaXmasConveyorBelt::LEFT)),
_right(Hand(PapaXmasConveyorBelt::RIGHT)),
_table(table), _belt(belt)
{
}

PapaXmasElf::~PapaXmasElf()
{
}

std::vector<std::string> PapaXmasElf::look()
{
    return (_table->look());
}

void PapaXmasElf::take(PapaXmasConveyorBelt::side side)
{
    if (side == PapaXmasConveyorBelt::LEFT) {
        _left.setObject(_belt->take());
    }
    else {
        _right.setObject(_belt->take());
    }
}

void PapaXmasElf::put(PapaXmasConveyorBelt::side side)
{
    if (side == PapaXmasConveyorBelt::LEFT) {
        _belt->put((Wrap *)_left.getObject());
        _left.reset();
    }
    else {
        _belt->put((Wrap *)_right.getObject());
        _right.reset();
    }
}

void PapaXmasElf::takeObject(PapaXmasConveyorBelt::side side, int idx)
{
    if (side == PapaXmasConveyorBelt::LEFT)
        _left.setObject(_table->take(idx));
    else
        _right.setObject(_table->take(idx));
}

void PapaXmasElf::putObject(PapaXmasConveyorBelt::side side)
{
    if (side == PapaXmasConveyorBelt::LEFT) {
        _table->put(_left.getObject());
        _left.reset();
    }
    else {
        _table->put(_right.getObject());
        _right.reset();
    }
}

bool PapaXmasElf::checkHands(const std::string id)
{
    if (_left.getObject() && _left.getObject()->getType() == id)
        return (true);
    if (_right.getObject() && _right.getObject()->getType() == id)
        return (true);
    if (_belt->getWrap() && _belt->getWrap()->getType() == id)
        return (true);
    return (false);
}

bool PapaXmasElf::canWrap()
{
    int i = 0;
    int check = 0;

    while (_table->lookObj(i) && _table->lookObj(i)->getType() != "object") {
        i++;
    }
    if (_table->lookObj(i) || (checkHands("object"))) {
        check += 1;
    }
    i = 0;
    while (_table->lookObj(i) && _table->lookObj(i)->getType() != "box") {
        i++;
    }
    if (_table->lookObj(i) || (checkHands("box"))) {
        check += 2;
    }
    i = 0;
    while (_table->lookObj(i) && _table->lookObj(i)->getType() != "giftpaper") {
        i++;
    }
    if (_table->lookObj(i) || (checkHands("giftpaper"))) {
        check += 4;
    }
    if (check == 7)
        return (true);
    return (false);
}

Object *PapaXmasElf::checkRetHands(const std::string id)
{
    Object *obj;
    if (_left.getObject()->getType() == id) {
        obj = _left.getObject();
        _left.reset();
        return (obj);
    }
    else if (_right.getObject()->getType() == id) {
        obj = _right.getObject();
        _right.reset();
        return (obj);
    }
    else if (_belt->getWrap()->getType() == id) {
        return (obj);
    }
    return (NULL);
}

Object *PapaXmasElf::getObjectByType(const std::string type)
{
    int i = 0;
    while (_table->lookObj(i) && _table->lookObj(i)->getType() != type) {
        i++;
    }
    if (_table->lookObj(i)) {
        return (_table->take(i));
    }
    return (checkRetHands(type));
}

void PapaXmasElf::createAGift()
{
    ConveyorBeltRand r_wr;

    while (!canWrap() && _table->look().size() != 11) {
        take(_belt->RIGHT);
        putObject(_belt->RIGHT);
        r_wr.randWrap(_belt);
    }
    if (!_table->look().size() == 0 || !canWrap()) {
        std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
    }
    else {
        _right.setObject(getObjectByType("box"));
        _left.setObject(getObjectByType("object"));
        auto box = _right.getObject();
        _right.reset();
        box->setObject(_left.getObject());
        _left.reset();
        _right.setObject(getObjectByType("giftpaper"));
        _right.getObject()->setObject(box);
        put(_belt->RIGHT);
        _left.pushOutButton(_belt);
    }
}