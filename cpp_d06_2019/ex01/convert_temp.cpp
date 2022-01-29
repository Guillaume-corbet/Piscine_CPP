/*
** EPITECH PROJECT, 2020
** day6
** File description:
** convert_temp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void display(float result, std::string str)
{
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result;
    std::cout << std::setw(16) << str << std::endl;
}

int main(void)
{
    float Celsius = 0.0;
    float Fahrenheit = 0.0;
    std::string value;
    std::string type;

    std::cin >> value >> type;
    if (type.find("Celsius") != std::string::npos) {
        Celsius = std::stof(value, 0);
        Fahrenheit = Celsius * 9 / 5 + 32;
        display(Fahrenheit, "Fahrenheit");
    } else if (type.find("Fahrenheit") != std::string::npos) {
        Fahrenheit = std::stof(value, 0);
        Celsius = 5.0 / 9.0 * ( Fahrenheit - 32 );
        display(Celsius, "Celsius");
    } else {
        return (84);
    }
    return (0);
}