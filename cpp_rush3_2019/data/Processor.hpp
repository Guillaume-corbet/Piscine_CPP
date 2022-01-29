/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Processor
*/

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>
#include <cstring>
#include <algorithm>
#include "FileManip.hpp"
#include "../monitor/IMonitorModule.hpp"

class Processor : public IMonitorModule {
	public:
		Processor();
		~Processor();
        void calc_cpu_usage();
        int check_string(std::string arg, std::string to_find, std::string en_to_find, std::string &var);
        int check_string(std::string arg, std::string to_find, std::string en_to_find, int &var);
        bool init_all_cpu_values();
        bool refresh();
        std::string getArchitecture()const;
        std::string getBoutism()const;
        std::string getModelName()const;
        std::string getConstructor()const;
        int getSpeed()const;
        int getUsage()const;
        int getVMin()const;
        int getVMax()const;
        int getNbCores()const;
        int getNbThreads()const;
        std::vector<int> getDataVect() const;
        char getCommandDisplay() const;
        void setCommandDisplay(char commandHide);
        bool isDisplay() const;
        void setDislay(bool display);
	protected:
        int _speed;
        int _usage;
        int all_usage_old;
        std::time_t old_time;

	private:
        std::string _architecture;
        std::string _boutism;
        std::string _model_name;
        std::string _constructor;
        int _vmin;
        int _vmax;
        int _nb_cores;
        int _nb_threads;
        char _commandHide;
        bool _display;
        std::vector<int> values_storage;
};

#endif /* !PROCESSOR_HPP_ */