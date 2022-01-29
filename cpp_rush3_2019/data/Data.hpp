/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include "Ram.hpp"
#include "Processor.hpp"
#include "Monitor.hpp"
#include "Network.hpp"

class Data {
	public:
		Data();
		~Data();
        bool refresh();
        Ram *getRam() const;
        Processor *getProcessor() const;
        Monitor *getMonitor() const;
        Network *getNetwork() const;
	protected:
	private:
        Ram *_ram;
        Processor *_processor;
        Monitor *_monitor;
        Network *_network;
};

#endif /* !DATA_HPP_ */
