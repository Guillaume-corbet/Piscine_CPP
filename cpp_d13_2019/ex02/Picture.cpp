/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    std::string line;
    std::ifstream file_r;

    file_r.open(file);
    if (!file_r.is_open()) {
        this->data = "ERROR";
        return;
    }
    while (getline (file_r,line))
    {
        this->data =this->data + line + "\n";
    }
    file_r.close();
}

Picture::Picture(const Picture &img)
{
    this->data = img.data;
}

Picture::~Picture()
{

}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string line;
    std::ifstream file_r;

    file_r.open(file);
    if (!file_r.is_open()) {
        this->data = "ERROR";
        return (false);
    }
    while (getline (file_r,line))
    {
        this->data =this->data + line + "\n";
    }
    file_r.close();
    return (true);
}

Picture &Picture::operator=(const Picture &img)
{
    this->data = img.data;
    return (*this);
}