/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar()
{
    this->move = 3;
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    if (plainchar < 65 || (plainchar > 90 && plainchar < 97) || plainchar > 122) {
        std::cout << plainchar;
        this->move = this->move + 1;
        if (this->move >= 26)
            this->move = this->move - 26;
        return;
    }
    if (plainchar >= 65 && plainchar <= 90) {
        if (plainchar + this->move > 90)
            plainchar = 65 + plainchar + this->move - 91;
        else
            plainchar = plainchar + this->move;
    } else if (plainchar >= 97 && plainchar <= 122) {
        if (plainchar + this->move > 122)
            plainchar = 97 + plainchar + this->move - 123;
        else
            plainchar = plainchar + this->move;
    }
    std::cout << plainchar;
    this->move = this->move + 1;
    if (this->move >= 26)
        this->move = this->move - 26;
}

void Cesar::decryptChar(char cipherchar)
{
    if (cipherchar < 65 || (cipherchar > 90 && cipherchar < 97) || cipherchar > 122) {
        std::cout << cipherchar;
        this->move = this->move + 1;
        if (this->move >= 26)
            this->move = this->move - 26;
        return;
    }
    if (cipherchar >= 65 && cipherchar <= 90) {
        if (cipherchar - this->move < 65)
            cipherchar = 90 + cipherchar - this->move - 64;
        else
            cipherchar = cipherchar - this->move;
    } else if (cipherchar >= 97 && cipherchar <= 122) {
        if (cipherchar - this->move < 97)
            cipherchar = 122 + cipherchar - this->move - 96;
        else
            cipherchar = cipherchar - this->move;
    }
    std::cout << cipherchar;
    this->move = this->move + 1;
    if (this->move >= 26)
        this->move = this->move - 26;
}

void Cesar::reset()
{
    this->move = 3;
}