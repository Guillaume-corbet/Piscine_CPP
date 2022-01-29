/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** sfml
*/
 
#include "sfml.hpp"

void graph::print_network(sf::Vector2f coor, std::vector<int> array)
{
    sf::Text text_name;
    sf::Text value;
    sf::Font font;
    sf::RectangleShape rectangle;
    sf::RectangleShape rect;
    float iterator = (window.getSize().x - coor.x - 2 * offset) / 60;
    float posx = coor.x + offset;

    rectangle.setSize(sf::Vector2f(iterator, window.getSize().y / 3 - 2 * offset));
    rect.setSize(sf::Vector2f(5, 10));
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(window.getSize().x - offset, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y - window.getSize().y / 3 + 2 * offset))};
    
    for (int i = 0; i < 60; i++) {
        rectangle.setPosition(posx, coor.y);
        rectangle.setScale(1, -(float)array[i] / 100);
        rectangle.setFillColor(sf::Color::Green);
        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(window.getSize().x - offset, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y - window.getSize().y / 3 + 2 * offset))};
        if (i%5 == 0 && i != 0) {
            rect.setPosition(posx, coor.y - 5);
        }
        window.draw(rectangle);
        window.draw(rect);
        if (i == 59) {
            sf::Vertex last[] = {sf::Vertex(sf::Vector2f(coor.x - 10, coor.y - rectangle.getSize().y * ((float)array[i] / 100))), sf::Vertex(sf::Vector2f(window.getSize().x - offset, coor.y - rectangle.getSize().y * ((float)array[i] / 100)))};
            window.draw(last, 2, sf::Lines);
            value.setString(std::to_string(array[i]));
            font.loadFromFile("flotta.otf");
            value.setFont(font);
            value.setPosition(coor.x + 4, coor.y - rectangle.getSize().y * ((float)array[i] / 100) - offset);
            value.setCharacterSize(15);
            window.draw(value);
        }
        posx += iterator;
    }
    text_name.setString( " (%)");
    font.loadFromFile("flotta.otf");
    text_name.setFont(font);
    text_name.setPosition(coor.x - 10, coor.y - window.getSize().y / 3 + offset);
    text_name.setCharacterSize(20);
    window.draw(text_name);
    window.draw(line, 4, sf::Lines);
}

void graph::print_graph(sf::Vector2f coor, std::vector<int> array, std::string name)
{
    sf::Text text_name;
    sf::Text value;
    sf::Text sec;
    sf::Font font;
    sf::RectangleShape rectangle;
    sf::RectangleShape rect;
    float iterator = (window.getSize().x - coor.x - 2 * offset) / 60;
    float posx = coor.x + offset;
    font.loadFromFile("flotta.otf");
    value.setFont(font);
    value.setCharacterSize(15);

    rectangle.setSize(sf::Vector2f(iterator, window.getSize().y / 3 - 2 * offset));
    rect.setSize(sf::Vector2f(5, 10));
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(window.getSize().x - offset, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y)), sf::Vertex(sf::Vector2f(coor.x, coor.y - window.getSize().y / 3 + 2 * offset))};
    
    for (int i = 0; i < 60; i++) {
        rectangle.setPosition(posx, coor.y);
        rectangle.setScale(1, -(float)array[i] / 100);
        rectangle.setFillColor(sf::Color::Magenta);
        if (i%5 == 0 && i != 0) {
            rect.setPosition(posx, coor.y - 5);
        }
        window.draw(rectangle);
        window.draw(rect);
        if (i == 59) {
            sf::Vertex last[] = {sf::Vertex(sf::Vector2f(coor.x - 10, coor.y - rectangle.getSize().y * ((float)array[i] / 100))), sf::Vertex(sf::Vector2f(window.getSize().x - offset, coor.y - rectangle.getSize().y * ((float)array[i] / 100)))};
            window.draw(last, 2, sf::Lines);
            value.setString(std::to_string(array[i]));
            value.setPosition(coor.x + 4, coor.y - rectangle.getSize().y * ((float)array[i] / 100) - offset);
            window.draw(value);
        }
        posx += iterator;
    }
    sec.setFont(font);
    sec.setString("s");
    sec.setCharacterSize(15);
    sec.setPosition(window.getSize().x - offset, coor.y);
    window.draw(sec);
    text_name.setString(name + " (%)");
    text_name.setCharacterSize(20);
    text_name.setFont(font);
    text_name.setPosition(coor.x - 10, coor.y - window.getSize().y / 3 + offset);
    window.draw(text_name);
    window.draw(line, 4, sf::Lines);
}

graph::graph()
{
    offset = 25;
    coord_info.x = offset;
    coord_info.y = offset;
    coord_cpu.x = window.getSize().x / 2 - offset;
    coord_cpu.y = window.getSize().y / 3 - offset;
    coord_ram.x = window.getSize().x / 2 - offset;
    coord_ram.y = 2 * (window.getSize().y / 3) - offset;
    coord_network.x = window.getSize().x / 2 - offset;
    coord_network.y = 3 * (window.getSize().y / 3) - offset;
    coord_temp.x = offset;
    coord_temp.y = window.getSize().y - offset;
    this->_commandChange = 'm';
    this->_commandQuit = 'q';
    this->_time = std::time(nullptr);
}

void graph::init_all()
{
    offset = 25;
    coord_info.x = offset;
    coord_info.y = offset;
    coord_cpu.x = window.getSize().x / 2 - offset;
    coord_cpu.y = window.getSize().y / 3 - offset;
    coord_ram.x = window.getSize().x / 2 - offset;
    coord_ram.y = 2 * (window.getSize().y / 3) - offset;
    coord_network.x = window.getSize().x / 2 - offset;
    coord_network.y = 3 * (window.getSize().y / 3) - offset;
    coord_temp.x = offset;
    coord_temp.y = window.getSize().y - offset;
    this->_commandChange = 'm';
    this->_commandQuit = 'q';
    this->_time = std::time(nullptr);
}

void graph::print_moni(Data *data)
{
    sf::Text print;
    sf::Font font;
    font.loadFromFile("flotta.otf");
    print.setFont(font);
    print.setCharacterSize(25);
    print.setString("Monitor\n-> SysName : " + data->getMonitor()->getSysName() + 
    "\n-> UserName : " + data->getMonitor()->getUserName() +
    "\n-> HostName : " + data->getMonitor()->getHostName() +
    "\n-> Operating system : " + data->getMonitor()->getOperatingSystem() +
    "\n-> Kernel version : " + data->getMonitor()->getKernelVersion() +
    "\n-> Date : " + data->getMonitor()->getDate() +
    "\n-> Model name : " + data->getProcessor()->getModelName() +
    "\n-> Architecture : " + data->getProcessor()->getArchitecture());
    print.setPosition(coord_info.x + 20, coord_info.y + 20);
    window.draw(print);
}

void graph::setCommandQuit(char command)
{
    _commandQuit = command;
}

char graph::getCommandQuit() const
{
    return(_commandQuit);
}

void graph::setCommandChange(char command)
{
    this->_commandChange = command;
}

char graph::getCommandChange() const
{
    return (this->_commandChange);
}

void graph::setTime(std::time_t time)
{
    this->_time = time;
}

std::time_t graph::getTime(void) const
{
    return (this->_time);
}

void graph::ChangeData(Data *data)
{
    std::time_t time = std::time(nullptr);
    
    if (this->getTime() + 1 <= time) {
        this->setTime(time);
        data->refresh();
    }
}

void graph::start(Data *data)
{
    window.create(sf::VideoMode(1920, 1080), "Htop", sf::Style::Resize | sf::Style::Close);
    //std::vector<int> i = {40, 100, 20, 24, 42, 67, 50, 68, 80, 38, 40, 41, 100, 24, 42, 67, 50, 68, 80, 38, 40, 41, 20, 24, 42, 67, 50, 68, 80, 38, 40, 41, 20, 24, 42, 67, 50, 68, 80, 38, 40, 41, 20, 24, 42, 67, 50, 68, 80, 38, 40, 41, 20, 24, 42, 67, 50, 68, 80, 38};
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Event event;
    int breakGame = 0;
    init_all();

    if (!texture.loadFromFile("fond.jpg"))
        return;
    sprite.setTexture(texture);
    while (window.isOpen()) {
        this->ChangeData(data);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == this->_commandQuit)
                    return;
                else if (event.text.unicode == this->_commandChange) {
                    window.close();
                    breakGame = 1;
                    break;
                } else if (event.text.unicode == data->getRam()->getCommandDisplay()) {
                    data->getRam()->setDislay(!data->getRam()->isDisplay());
                } else if (event.text.unicode == data->getMonitor()->getCommandDisplay()) {
                    data->getMonitor()->setDislay(!data->getMonitor()->isDisplay());
                } else if (event.text.unicode == data->getProcessor()->getCommandDisplay()) {
                    data->getProcessor()->setDislay(!data->getProcessor()->isDisplay());
                }
            }
        }
        if (breakGame == 1)
            break;
        window.clear();
        window.draw(sprite);
        if (data->getMonitor()->isDisplay())
            print_moni(data);
        if (data->getProcessor()->isDisplay())
            print_graph(coord_cpu, data->getProcessor()->getDataVect(), "CPU");
        if (data->getRam()->isDisplay())
            print_graph(coord_ram, data->getRam()->getDataVect() ,"RAM");
        //print_network(coord_network, i);
        window.display();
    }
    Ncurses ncurses;
    ncurses.start(data);
    return;
}