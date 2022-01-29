/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** sfml
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "../data/Data.hpp"
#include "../monitor/IMonitorDisplay.hpp"
#include <ctime>
#include "../ncurses/Ncurses.hpp"

#ifndef SFML_HPP_
#define SFML_HPP_

class graph : public IMonitorDisplay{
    public:
        //int main_sfml(Data *data);
        graph();
        void init_all();
        void print_network(sf::Vector2f coor, std::vector<int> array);
        void print_graph(sf::Vector2f size, std::vector<int> array, std::string);
        void print_moni(Data *data);

        void ChangeData(Data *data);
        void start(Data *data);
        void setCommandChange(char command);
        char getCommandChange() const;
        void setCommandQuit(char command);
        char getCommandQuit() const;
        void setTime(std::time_t time);
        std::time_t getTime() const;

        ~graph(){};
    private:
        sf::RenderWindow window;
        sf::Vector2f coord_info;
        sf::Vector2f coord_cpu;
        sf::Vector2f coord_ram;
        sf::Vector2f coord_network;
        sf::Vector2f coord_temp;
        unsigned offset;
        char _commandChange;
        char _commandQuit;
        std::time_t _time;

};

#endif /* !SFML_HPP_ */
