/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ram
*/

#include "Ram.hpp"

Ram::Ram()
{
    std::vector<std::string> ram;
    
    std::system("free -k > ramHtop.txt");
    ram = getSysFile("ramHtop.txt");
    std::system("rm ramHtop.txt");
    ram.erase(ram.begin());
    this->parseRam(ram.at(0), this->_ramTotal, this->_ramUsed, this->_ramFree);
    this->parseRam(ram.at(1), this->_swapTotal, this->_swapUsed, this->_swapFree);
    this->_display = true;
    this->_commandHide = 'h';
    for (int i = 0; i < 60; i++)
        values_storage.push_back(0);
}

Ram::~Ram()
{

}

bool Ram::parseRam(std::string str, int &total, int &used, int &free)
{
    size_t i = 0;
    size_t j = 0;

    while (str.size() > i && str.at(i) < '0' || str.at(i) > '9')
        i = i + 1;
    j = i;
    while (str.size() > i && str.at(i) >= '0' && str.at(i) <= '9')
        i = i + 1;
    total = atoi(str.substr(j, i - j).c_str());
    while (str.size() > i && str.at(i) < '0' || str.at(i) > '9')
        i = i + 1;
    j = i;
    while (str.size() > i && str.at(i) >= '0' && str.at(i) <= '9')
        i = i + 1;
    used = atoi(str.substr(j, i - j).c_str());
    if (str.size() > 50)
        values_storage.push_back(used * 100 / total);
    while (values_storage.size() > 60)
        values_storage.erase(values_storage.begin());
    while (str.size() > i && str.at(i) < '0' || str.at(i) > '9')
        i = i + 1;
    j = i;
    while (str.size() > i) {
        j = i - 1;
        while (str.size() > i && str.at(i) >= '0' && str.at(i) <= '9')
            i = i + 1;
        i = i + 1;
    }
    free = atoi(str.substr(j, i - j).c_str());

    return (true);
}

bool Ram::refresh()
{
    std::vector<std::string> ram;

    std::system("free -k > ramHtop.txt");
    ram = getSysFile("ramHtop.txt");
    std::system("rm ramHtop.txt");
    ram.erase(ram.begin());

    this->parseRam(ram.at(0), this->_ramTotal, this->_ramUsed, this->_ramFree);
    this->parseRam(ram.at(1), this->_swapTotal, this->_swapUsed, this->_swapFree);
    return (true);
}

int Ram::getRamTotal() const
{
    return (this->_ramTotal);
}

int Ram::getRamUsed() const
{
    return (this->_ramUsed);
}

int Ram::getRamFree() const
{
    return (this->_ramFree);
}

int Ram::getSwapTotal() const
{
    return (this->_swapTotal);
}

int Ram::getSwapUsed() const
{
    return (this->_swapUsed);
}

int Ram::getSwapFree() const
{
    return (this->_swapFree);
}

char Ram::getCommandDisplay() const
{
    return (this->_commandHide);
}

void Ram::setCommandDisplay(char commandHide)
{
    this->_commandHide = commandHide;
}

bool Ram::isDisplay() const
{
    return (this->_display);
}

void Ram::setDislay(bool display)
{
    this->_display = display;
}

std::vector<int> Ram::getDataVect() const
{
    return (values_storage);
}