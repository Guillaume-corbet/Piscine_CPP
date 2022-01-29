/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "../data/Data.hpp"

class IMonitorDisplay {
	public:
		IMonitorDisplay(){};
		virtual ~IMonitorDisplay(){};
        virtual void start(Data *data) = 0;
        virtual void setCommandChange(char command) = 0;
        virtual char getCommandChange() const = 0;
        virtual void setCommandQuit(char command) = 0;
        virtual char getCommandQuit() const = 0;
	protected:
	private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
