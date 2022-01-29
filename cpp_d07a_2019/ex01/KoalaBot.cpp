/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot()
{

}

void KoalaBot::setParts(const Arms &arms)
{
    this->arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    this->legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    this->head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms new_arms = arms;

    arms = this->arms;
    this->arms = new_arms;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs new_legs = legs;

    legs = this->legs;
    this->legs = new_legs;
}

void KoalaBot::swapParts(Head &head)
{
    Head new_head = head;

    head = this->head;
    this->head = new_head;
}

void KoalaBot::informations() const
{
    Arms arms = this->arms;
    Legs legs = this->legs;
    Head head = this->head;

    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    arms.informations();
    legs.informations();
    head.informations();
}

bool KoalaBot::status() const
{
    Arms arms = this->arms;
    Legs legs = this->legs;
    Head head = this->head;

    if (arms.isFunctional() && head.isFunctional() && legs.isFunctional())
        return (true);
    return (false);
}
