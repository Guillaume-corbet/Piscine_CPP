/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Monitor
*/

#include "Monitor.hpp"

Monitor::Monitor()
{
    init_value_from_cmd("date", _date);
    init_value_from_cmd("hostname", _hostname);
    init_value_from_cmd("whoami", _username);
    init_value_from_cmd("uname -v", _kernel_version);
    init_value_from_cmd("uname -o", _operating_system);
    init_value_from_cmd("uname -s", _sys_name);
    this->_display = true;
    this->_commandHide = 'j';
}

Monitor::~Monitor()
{
}

bool Monitor::refresh()
{
    init_value_from_cmd("date", _date);
    return (true);
}

void Monitor::init_value_from_cmd(std::string cmd, std::string &var)
{
    std::string tmp_cmd = cmd;
    cmd.append(" > tmp_file_monitor_values0.txt");
    std::system(cmd.c_str());
    std::string monitor_values = getFile("tmp_file_monitor_values0.txt");
    std::system("rm tmp_file_monitor_values0.txt");
    if (monitor_values != "")
        var = monitor_values;
}

void Monitor::init_value_from_file(std::string filename, std::string &var)
{
    var = getFile(filename);
}

std::string Monitor::getSysName()
{
    return (_sys_name);
}

std::string Monitor::getUserName()
{
    return (_username);
}

std::string Monitor::getHostName()
{
    return (_hostname);
}

std::string Monitor::getOperatingSystem()
{
    return (_operating_system);
}

std::string Monitor::getKernelVersion()
{
    return (_kernel_version);
}

std::string Monitor::getDate()
{
    return (_date);
}

void Monitor::setCommandDisplay(char command)
{
    this->_commandHide = command;
}

char Monitor::getCommandDisplay() const
{
    return (this->_commandHide);
}

bool Monitor::isDisplay() const
{
    return (this->_display);
}

void Monitor::setDislay(bool display)
{
    this->_display = display;
}