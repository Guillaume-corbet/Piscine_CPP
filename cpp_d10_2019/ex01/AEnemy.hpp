/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AEnemy
*/

#pragma once

#include <string>
#include <iostream>

class AEnemy {
	public:
		AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();
        virtual void takeDamage(int damage);
        std::string const getType() const;
        int getHP() const;
    protected:
        void setHp(int hp);
	private:
        const std::string _type;
        int _hp;
};
