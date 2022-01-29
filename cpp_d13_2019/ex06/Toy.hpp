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
        class Error {
            public:
                enum ErrorType {UNKNOWN, PICTURE, SPEAK};
                Error();
                ~Error();
                std::string what() const;
                std::string where() const;
                ErrorType type;
        };
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
        virtual bool speak(std::string say);
        Picture *getPicture() const;
        void setTxtPicture(std::string txt);
        virtual bool speak_es(std::string say);
        Error getLastError() const;
	protected:
	private:
        ToyType _type;
        std::string _name;
        Picture *_picture;
        Error error;
};

Toy &operator<<(Toy &obj, const std::string txt);
std::ostream &operator<<(std::ostream &s, const Toy &tmp);