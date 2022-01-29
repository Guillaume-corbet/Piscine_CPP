/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "FileManip.hpp"
#include "../monitor/IMonitorModule.hpp"

class Ram : public IMonitorModule {
	public:
		Ram();
		~Ram();
        bool refresh();
        int getRamTotal() const;
        int getRamUsed() const;
        int getRamFree() const;
        int getSwapTotal() const;
        int getSwapUsed() const;
        int getSwapFree() const;
        char getCommandDisplay() const;
        void setCommandDisplay(char commandHide);
        bool isDisplay() const;
        void setDislay(bool display);
        std::vector<int> getDataVect() const;
	protected:
	private:
        bool parseRam(std::string str, int &total, int &used, int &free);
        int _swapFree;
        int _ramFree;
        int _swapUsed;
        int _ramUsed;
        int _ramTotal;
        int _swapTotal;
        char _commandHide;
        bool _display;
        std::vector<int> values_storage;
};

#endif /* !RAM_HPP_ */