/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Monitor
*/

#ifndef MONITOR_HPP_
#define MONITOR_HPP_

#include <string>
#include "FileManip.hpp"
#include "../monitor/IMonitorModule.hpp"

class Monitor : public IMonitorModule {
	public:
		Monitor();
		~Monitor();
		void init_value_from_file(std::string filename, std::string &var);
		void init_value_from_cmd(std::string cmd, std::string &var);
		std::string getSysName();
		std::string getUserName();
		std::string getHostName();
		std::string getOperatingSystem();
		std::string getKernelVersion();
		std::string getDate();
		bool refresh();
        void setCommandDisplay(char command);
        char getCommandDisplay() const;
        bool isDisplay() const;
        void setDislay(bool display);
	protected:
	private:
		std::string _sys_name;
		std::string _username;
		std::string _hostname;
		std::string _operating_system;
		std::string _kernel_version;
		std::string _date;
        char _commandHide;
        bool _display;
};

#endif /* !MONITOR_HPP_ */