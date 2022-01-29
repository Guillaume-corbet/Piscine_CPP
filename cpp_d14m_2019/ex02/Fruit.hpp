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
		Fruit(std::string name, int vitamins);
		virtual ~Fruit();
        int getVitamins() const;
        virtual std::string getName() const;
	protected:
        int _vitamins;
        const std::string _name;
	private:
};