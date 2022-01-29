/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>
#include "DroidMemory.hpp"

class Droid {
	public:
		Droid(std::string serialNb);
        Droid(const Droid &tmp);
		~Droid();
        std::string getId() const ;
        void setId(std::string Id);
        size_t getEnergy() const ;
        void setEnergy(size_t Energy);
        size_t getAttack() const;
        size_t getToughness() const;
        std::string getStatus() const;
        void setStatus(std::string *Status);
        bool operator==(const Droid &tmp) const;
        bool operator!=(const Droid &tmp) const;
        Droid &operator=(const Droid &tmp);
        void operator<<(size_t &power);
        bool operator()(const std::string *task, size_t exp);
        void setBattleData(DroidMemory *tmp);
        DroidMemory *getBattleData() const;

	private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &s, const Droid &tmp);

#endif /* !DROID_HPP_ */
