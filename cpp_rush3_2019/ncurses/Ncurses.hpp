/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "Terminal.hpp"
#include <string>
#include <iostream>
#include "../monitor/IMonitorDisplay.hpp"
#include "../sfml/sfml.hpp"

class Ncurses : public IMonitorDisplay {
	public:
		Ncurses();
		~Ncurses();
        void start(Data *data);
        void setCommandChange(char command);
        char getCommandChange() const;
        void setCommandQuit(char command);
        char getCommandQuit() const;
        void ChangeData(Terminal *terminal, Data *data);
        int event(Terminal *terminal, Data *data);
	protected:
	private:
        char _commandQuit;
        char _commandChange;
};

#endif /* !NCURSES_HPP_ */
