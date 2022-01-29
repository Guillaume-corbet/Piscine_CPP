/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serialNb):Attack(25), Toughness(15)
{
    this->Id = serialNb;
    this->Energy = 50;
    this->Status = new std::string("Standing by");
    this->BattleData = new DroidMemory();
    std::cout << "Droid '" << serialNb << "' Activated" << std::endl;
}

Droid::Droid(const Droid &tmp):Attack(tmp.Attack), Toughness(tmp.Toughness)
{
    this->Id = tmp.Id;
    this->Status = tmp.Status;
    this->Energy = 50;
    this->BattleData = new DroidMemory(tmp.BattleData->getExp(), tmp.BattleData->getFingerprint());
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (this->Id);
}

void Droid::setId(std::string Id)
{
    this->Id = Id;
}

size_t Droid::getEnergy() const
{
    return (this->Energy);
}

void Droid::setEnergy(size_t Energy)
{
    if (Energy < 101)
        this->Energy = Energy;
    else
        this->Energy = 100;
}

size_t Droid::getAttack() const
{
    return (this->Attack);
}

size_t Droid::getToughness() const
{
    return (this->Toughness);
}

std::string Droid::getStatus() const
{
    return ((*this->Status));
}

void Droid::setStatus(std::string *Status)
{
    this->Status = Status;
}

bool Droid::operator==(const Droid &tmp) const
{
    if ((*this->Status) == (*tmp.Status)) {
        return (true);
    }
    return (false);
}

bool Droid::operator!=(const Droid &tmp) const
{
    if ((*this->Status) != (*tmp.Status)) {
        return (true);
    }
    return (false);
}

Droid &Droid::operator=(const Droid &tmp)
{
    this->Id = tmp.Id;
    this->Status = tmp.Status;
    this->Energy = 50;
    this->BattleData = tmp.BattleData;
    return (*this);
}

void Droid::operator<<(size_t &power)
{
    size_t max = 100 - this->Energy;

    if (max > power) {
        this->Energy = this->Energy + power;
        power = 0;
    } else {
        this->Energy = this->Energy + max;
        power = power - max;
    }
}

std::ostream &operator<<(std::ostream &s, const Droid &tmp)
{
    s << "Droid '" << tmp.getId() << "', " << tmp.getStatus() << ", " << tmp.getEnergy();
    return (s);
}

void Droid::setBattleData(DroidMemory *tmp)
{
    this->BattleData = tmp;
}

DroidMemory *Droid::getBattleData() const
{
    return (this->BattleData);
}

bool Droid::operator()(const std::string *task, size_t exp)
{
    if (this->Energy <= 10) {
        this->Energy = 0;
        this->setStatus(new std::string("Battery Low"));
        return (false);
    }
    if (this->BattleData->getExp() < exp) {
        this->Energy = this->Energy - 10;
        this->BattleData->setExp(this->BattleData->getExp() + exp);
        this->setStatus(new std::string((*task) + " - Failed!"));
        return (false);
    } else {
        this->Energy = this->Energy - 10;
        this->BattleData->setExp(this->BattleData->getExp() + (exp / 2));
        this->setStatus(new std::string((*task) + " - Completed!"));
        return (true);
    }
}