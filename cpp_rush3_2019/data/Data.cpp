/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Data
*/

#include "Data.hpp"

Data::Data()
{
    this->_ram = new Ram();
    this->_processor = new Processor();
    this->_monitor = new Monitor();
    this->_network = new Network();
}

Data::~Data()
{
}

bool Data::refresh()
{
    if (!this->_ram->refresh()) {
        std::cerr << "Error get info ram" << std::endl;
        return (false);
    }
    if (!this->_processor->refresh()) {
        std::cerr << "Error get info processor" << std::endl;
        return (false);
    }
    if (!this->_monitor->refresh()) {
        std::cerr << "Error get info monitor" << std::endl;
        return (false);
    }
    return (true);
}

Ram *Data::getRam() const
{
    return (this->_ram);
}

Processor *Data::getProcessor() const
{
    return (this->_processor);
}

Monitor *Data::getMonitor() const
{
    return (this->_monitor);
}

Network *Data::getNetwork() const
{
    return (this->_network);
}