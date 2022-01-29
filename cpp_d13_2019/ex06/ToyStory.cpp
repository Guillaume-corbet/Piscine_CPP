/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(std::string filename, Toy toy1, bool(Toy::*func1)(std::string say), Toy toy2, bool(Toy::*func2)(std::string say))
{
    size_t i = 0;
    int turn = 0;
    std::ifstream file;
    std::vector<std::string> lineFile;
    std::string line;

    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    while (getline(file, line)) {
        lineFile.push_back(line);
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    while (i < lineFile.size()) {
        if (lineFile.at(i).rfind("picture", 0) == 0) {
            turn = turn - 1;
            if ((turn % 2) == 0) {
                if (!toy1.setAscii(lineFile.at(i).substr(8))) {
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() << std::endl;
                    break;
                }
                std::cout << toy1.getAscii() << std::endl;
            } else {
                if (!toy2.setAscii(lineFile.at(i).substr(8))) {
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                    break;
                }
                std::cout << toy2.getAscii() << std::endl;
            }
        }
        if ((turn % 2) == 0) {
            if (!(toy1.*func1)(lineFile.at(i))) {
                std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() << std::endl;
                break;
            }
        } else {
            if (!(toy2.*func2)(lineFile.at(i))) {
                std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                break;
            }
        }
        turn = turn + 1;
        i = i + 1;
    }
    file.close();
}