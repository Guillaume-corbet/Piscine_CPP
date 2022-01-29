/*
** EPITECH PROJECT, 2020
** day6
** File description:
** cat
*/

#include <iostream>
#include <fstream>
#include <string>

void cat(std::string str)
{
    std::string line;
    std::ifstream file;

    file.open(str);
    if (!file.is_open()) {
        std::cerr << "my_cat: " << str << ": No such file or directory" << std::endl;
        return;
    }
    while (getline (file,line))
    {
        std::cout << line;
        if (!file.eof())
            std::cout << std::endl;
    }
    file.close();
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }
    while (argc > i) {
        cat(argv[i]);
        i = i + 1;
    }
    return (0);
}