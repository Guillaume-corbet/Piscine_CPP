/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#pragma once

#include <string>
#include <iostream>
#include "Picture.hpp"

class Toy {
	public:
        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
		Toy();
        Toy(ToyType type, std::string name, std::string filename);
        Toy(const Toy &old);
		~Toy();
        std::string getName() const;
        void setName(std::string name);
        ToyType getType() const;
        bool setAscii(std::string file);
        std::string getAscii() const;
        Toy &operator=(const Toy &toy);
        virtual void speak(std::string say);
	protected:
	private:
        ToyType _type;
        std::string _name;
        Picture *_picture;
};