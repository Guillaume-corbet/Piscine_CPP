/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    this->move = 0;
    this->key = key;
}

OneTime::~OneTime()
{

}

void OneTime::encryptChar(char plainchar)
{
    int change = 0;

    if (this->key.at(this->move) >= 65 && this->key.at(this->move) <= 90)
        change = this->key.at(this->move) - 65;
    else if (this->key.at(this->move) >= 97 && this->key.at(this->move) <= 122)
        change = this->key.at(this->move) - 97;

    if (plainchar < 65 || (plainchar > 90 && plainchar < 97) || plainchar > 122) {
        std::cout << plainchar;
        this->move = this->move + 1;
        if (this->move >= this->key.size())
            this->move = this->move - this->key.size();
        return;
    }

    if (plainchar >= 65 && plainchar <= 90) {
        if (plainchar + change > 90)
            plainchar = 65 + plainchar + change - 91;
        else
            plainchar = plainchar + change;
    } else if (plainchar >= 97 && plainchar <= 122) {
        if (plainchar + change > 122)
            plainchar = 97 + plainchar + change - 123;
        else
            plainchar = plainchar + change;
    }

    std::cout << plainchar;
    this->move = this->move + 1;
    if (this->move >= this->key.size())
        this->move = this->move - this->key.size();
}

void OneTime::decryptChar(char cipherchar)
{
    int change = 0;

    if (this->key.at(this->move) >= 65 && this->key.at(this->move) <= 90)
        change = this->key.at(this->move) - 65;
    else if (this->key.at(this->move) >= 97 && this->key.at(this->move) <= 122)
        change = this->key.at(this->move) - 97;

    if (cipherchar < 65 || (cipherchar > 90 && cipherchar < 97) || cipherchar > 122) {
        std::cout << cipherchar;
        this->move = this->move + 1;
        if (this->move >= this->key.size())
            this->move = this->move - this->key.size();
        return;
    }

    if (cipherchar >= 65 && cipherchar <= 90) {
        if (cipherchar - change < 65)
            cipherchar = 90 + cipherchar - change - 64;
        else
            cipherchar = cipherchar - change;
    } else if (cipherchar >= 97 && cipherchar <= 122) {
        if (cipherchar - change < 97)
            cipherchar = 122 + cipherchar - change - 96;
        else
            cipherchar = cipherchar - change;
    }

    std::cout << cipherchar;
    this->move = this->move + 1;
    if (this->move >= this->key.size())
        this->move = this->move - this->key.size();
}

void OneTime::reset()
{
    this->move = 0;
}