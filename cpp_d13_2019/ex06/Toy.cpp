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
    this->error = Error();
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    this->_type = type;
    this->_name = name;
    this->_picture = new Picture(filename);
    this->error = Error();
}

Toy::Toy(const Toy &toy)
{
    this->_type = toy._type;
    this->_name = toy._name;
    this->_picture = toy._picture;
    this->error = toy.error;
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
    bool ret = this->_picture->getPictureFromFile(file);
    if (ret == false) {
        this->error.type = this->error.PICTURE;
    }
    return (ret);
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
    this->error = toy.error;
    return (*this);
}

bool Toy::speak(std::string say)
{
    std::cout << this->_name << " \"" << say << "\"" << std::endl;
    return (true);
}

bool Toy::speak_es(std::string say)
{
    if (this->getType() == BUZZ) {
        std::cout << "BUZZ: " << this->getName() << " senorita \"" << say << "\" senorita" << std::endl;
        return (true);
    }
    this->error.type = this->error.SPEAK;
    return (false);
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

Toy::Error::Error()
{
    this->type = UNKNOWN;
}

std::string Toy::Error::what() const
{
    if (this->type == PICTURE)
        return ("bad new illustration");
    else if (this->type == SPEAK)
        return ("wrong mode");
    else
        return ("");
}

std::string Toy::Error::where() const
{
    if (this->type == PICTURE)
        return ("setAscii");
    else if (this->type == SPEAK)
        return ("speak_es");
    else
        return ("");
}

Toy::Error Toy::getLastError() const
{
    return (this->error);
}

Toy::Error::~Error()
{

}