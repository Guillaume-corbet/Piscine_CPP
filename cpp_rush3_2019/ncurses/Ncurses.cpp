/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    this->_commandChange = 'm';
    this->_commandQuit = 'q';
}

Ncurses::~Ncurses()
{

}

int Ncurses::event(Terminal *terminal, Data *data)
{
    int ch = 0;

    ch = getch();
    if (ch == this->_commandQuit) {
        terminal->printEnd();
        endwin();
        exit(0);
    }
    else if (ch == 'p') {
        if(terminal->pauseMenu() == 42) {
            terminal->printEnd();
            endwin();
            exit(0);
        }
    } else if (ch == this->_commandChange) {
        return (42);
    } else if (ch == data->getRam()->getCommandDisplay()) {
        data->getRam()->setDislay(!data->getRam()->isDisplay());
    } else if (ch == data->getMonitor()->getCommandDisplay()) {
        data->getMonitor()->setDislay(!data->getMonitor()->isDisplay());
    } else if (ch == data->getProcessor()->getCommandDisplay()) {
        data->getProcessor()->setDislay(!data->getProcessor()->isDisplay());
    } else if (ch == data->getNetwork()->getCommandDisplay()) {
        data->getNetwork()->setDislay(!data->getNetwork()->isDisplay());
    }
    return (0);
}

void Ncurses::ChangeData(Terminal *terminal, Data *data)
{
    std::time_t time = std::time(nullptr);
    
    if (terminal->getTime() + 1 <= time) {
        terminal->setTime(time);
        data->refresh();
        clear();
    }
}

void Ncurses::start(Data *data)
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    clear();
    curs_set(0);
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(4));
    Terminal *terminal = new Terminal(0, 0);
    while (1) {
        terminal->terminalSizeChange();
        if (terminal->terminalTooSmall() == 42)
            break;
        ChangeData(terminal, data);
        terminal->printMainScreen(data, this->_commandChange);
        if (event(terminal, data) == 42) {
            break;
        }
        refresh();
    }
    endwin();
    graph sfml;
    sfml.start(data);
}

void Ncurses::setCommandChange(char command)
{
    this->_commandChange = command;
}

char Ncurses::getCommandChange() const
{
    return (this->_commandChange);
}

void Ncurses::setCommandQuit(char command)
{
    this->_commandQuit = command;
}

char Ncurses::getCommandQuit() const
{
    return (this->_commandQuit);
}