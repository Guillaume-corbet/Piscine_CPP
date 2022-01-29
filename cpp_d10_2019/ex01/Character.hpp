/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character
*/

#pragma once

#include "AEnemy.hpp"
#include "AWeapon.hpp"

class Character {
	public:
		Character(const std::string &name);
        virtual ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const getName() const;
        int getAP() const;
        AWeapon *getWeapon() const;
    protected:
        void setAP(int ap);
	private:
        const std::string _name;
        int _AP;
        AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &s, const Character &tmp);