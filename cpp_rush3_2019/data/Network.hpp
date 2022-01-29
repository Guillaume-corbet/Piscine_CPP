/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "FileManip.hpp"
#include "../monitor/IMonitorModule.hpp"

class Network : public IMonitorModule {
	public:
		Network();
		~Network();
        bool refresh();
        char getCommandDisplay() const;
        void setCommandDisplay(char commandHide);
        bool isDisplay() const;
        void setDislay(bool display);
        int getNetworkStability() const;
        void init_network_var(std::string cmd, int &quality, int &att);
        int getNetworkQuality() const;
	protected:
	private:
        char _commandHide;
        bool _display;
        int _network_Att;
        int _quality;
        std::vector<int> values_att;
        std::vector<int> values_qua;
};

#endif /* !NETWORK_HPP_ */