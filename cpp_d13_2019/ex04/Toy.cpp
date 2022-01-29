/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture = new Picture();
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    this->_type = type;
    this->_name = name;
    this->_picture = new Picture(filename);
}

Toy::Toy(const Toy &toy)
{
    this->_type = toy._type;
    this->_name = toy._name;
    this->_picture = toy._picture;
}

Toy::~Toy()
{

}

std::string Toy::getName() const
{
    return (this->_name);
}

void Toy::setName(std::string name)
{
    this->_name = name;
}

Toy::ToyType Toy::getType() const
{
    return (this->_type);
}

bool Toy::setAscii(std::string file)
{
    return (this->_picture->getPictureFromFile(file));
}

std::string Toy::getAscii() const
{
    return (this->_picture->data);
}

Toy &Toy::operator=(const Toy &toy)
{
    this->_type = toy._type;
    this->_name = toy._name;
    this->_picture = toy._picture;
    return (*this);
}

void Toy::speak(std::string say)
{
    std::cout << this->_name << " \"" << say << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Toy &tmp)
{
    s << tmp.getName() << std::endl << tmp.getAscii() << std::endl;
    return (s);
}

Picture *Toy::getPicture() const
{
    return (this->_picture);
}

void Toy::setTxtPicture(std::string txt)
{
    this->_picture->data = txt;
}

Toy &operator<<(Toy &obj, const std::string txt)
{
    obj.setTxtPicture(txt);
    return (obj);
}