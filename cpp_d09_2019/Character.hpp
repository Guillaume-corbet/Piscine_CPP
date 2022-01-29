/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#pragma once

#include <string>
#include <iostream>

class Character {
	public:
        enum AttackRange {CLOSE, RANGE};
		Character(const std::string &name, int level);
		~Character();
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        int getStamina() const;
        int getStrength() const;
        int getSpirit() const;
        int getAgility() const;
        int getIntelligence() const;
        AttackRange Range;
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);
    protected:
        Character(const std::string &name, int level, int Stamina, int Spirit, int Agility, int strength, int intelligence);
        void setHealth(int health);
        void setEnergy(int energy);
        void setStrength(int strength);
        int Stamina;
        int Strength;
        int Intelligence;
        int Spirit;
        int Agility;
    private:
        const std::string name;
        int Level;
        int Health;
        int Energy;
    };