/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Network
*/

#include "Network.hpp"

Network::Network()
{
    this->_display = true;
    this->_commandHide = 'l';
    this->_network_Att = 0;
    this->_quality = 0;
    for (int i = 0; i < 60; i++) {
        values_att.push_back(0);
        values_qua.push_back(0);
    }
}

Network::~Network()
{

}

void Network::init_network_var(std::string cmd, int &quality, int &att)
{
    std::string tmp_cmd = cmd;
    cmd.append(" > tmp_file_network_values0.txt");
    std::system(cmd.c_str());
    std::string network_values = getFile("tmp_file_network_values0.txt");
    std::system("rm tmp_file_network_values0.txt");
    int i = 0;
    int j = 0;
    if (network_values.size() == 0)
        return;
    while (network_values[i] && network_values[i] != '=')
        i++;
    j = i;
    while (network_values[j] && network_values[j] != '/')
        j++;
    _quality = stoi(network_values.substr(i, j - i));
    values_qua.push_back(_quality);
    while (values_qua.size() > 60)
        values_qua.erase(values_qua.begin());
    while (network_values[i] && network_values[i] != '=')
        i++;
    j = i;
    while (network_values[j] && network_values[j] != ' ')
        j++;
    _network_Att = stoi(network_values.substr(i, j - i));
    values_att.push_back(_network_Att);
    while (values_att.size() > 60)
        values_att.erase(values_att.begin());
}

char Network::getCommandDisplay() const
{
    return (this->_commandHide);
}

void Network::setCommandDisplay(char commandHide)
{
    this->_commandHide = commandHide;
}

bool Network::isDisplay() const
{
    return (this->_display);
}

void Network::setDislay(bool display)
{
    this->_display = display;
}

bool Network::refresh()
{
    init_network_var("iwconfig wlp2s0 | grep -i quality", _quality, _network_Att);
    return (true);
}

int Network::getNetworkStability() const
{
    return (this->_network_Att);
}

int Network::getNetworkQuality() const
{
    return (this->_quality);
}