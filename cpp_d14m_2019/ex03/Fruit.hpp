/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

#pragma once

#include <string>
#include <iostream>

class Fruit {
	public:
		Fruit();
        Fruit(int vitamins, std::string name);
		virtual ~Fruit();
        int getVitamins() const;
        std::string getName() const;
	protected:
	private:
        int _vitamins;
        std::string _name;
};