/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** Terminal
*/

#pragma once

#include <ncurses.h>
#include <ctime>
#include <string>
#include "../data/Data.hpp"

class Terminal {
	public:
		Terminal(int cols, int lines);
		~Terminal();
        int getCols() const;
        int getLines() const;
        void terminalSizeChange();
        int terminalTooSmall();
        int pauseMenu(); 
        void printHtop();
        void printComputer();
        void printChangeMode(char change);
        void printHeader(char change);
        void printUbuntu();
        void printName();
        void printEnd();
        void printBox();
        void printLine();
        void printMiddle();
        void printRam(Ram *ram);
        void printComputer(Processor *processor, Monitor *monitor);
        void printProcessor(Processor *processor);
        void printNetwork(Network *network);
        void printMainScreen(Data *data, char change);
        std::time_t getTime() const;
        void setTime(std::time_t time);
	protected:
        void setCols(int cols);
        void setLines(int lines);
	private:
        int _cols;
        int _lines;
        std::time_t time;
};