/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Processor
*/

#include "Processor.hpp"

Processor::Processor()
{
    if (!init_all_cpu_values())
        std::cerr << "Error while initializing CPU values" << std::endl;
    for (int i = 0; i < 60; i++)
        values_storage.push_back(0);
    calc_cpu_usage();
    this->_commandHide = 'k';
    this->_display = true;
}

Processor::~Processor()
{
}

int Processor::check_string(std::string arg, std::string to_find, std::string en_to_find, std::string &var)
{
    unsigned int i = 0;
    std::string new_str;

    if (arg.find(to_find) == std::string::npos && arg.find(en_to_find) == std::string::npos)
        return (0);
    while (arg[i] && arg[i] != ':') {
        i++;
    }
    i++;
    while (arg[i] && arg[i] == ' ') {
        i++;
    }
    if (arg[i]) {
        new_str = arg.substr(i);
        var = new_str;
        return (1);
    }
    return (0);
}

int Processor::check_string(std::string arg, std::string to_find, std::string en_to_find, int &var)
{
    unsigned int i = 0;
    std::string new_str;

    if (arg.find(to_find) == std::string::npos && arg.find(en_to_find) == std::string::npos)
        return (0);
    while (arg[i] && arg[i] != ':')
        i++;
    i++;
    while (arg[i] && arg[i] == ' ')
        i++;
    if (arg[i]) {
        new_str = arg.substr(i, arg.size() - i);
        int nb2 = stoi(new_str);
        var = nb2;
        return (1);
    }
    return (0);
}

bool Processor::init_all_cpu_values()
{
    std::string cmd = "lscpu > tmp_file_cpu_values0.txt";
    std::system(cmd.c_str());
    int count = 0;
    std::vector<std::string> cpu_values = getSysFile("tmp_file_cpu_values0.txt");

    std::system("rm tmp_file_cpu_values0.txt");
    for (unsigned int i = 0; i < cpu_values.size(); i++) {
        count += check_string(cpu_values.at(i), "Architecture", "Architecture", _architecture);
        count += check_string(cpu_values.at(i), "Boutisme", "Byte Order:", _boutism);
        count += check_string(cpu_values.at(i), "Nom de modèle", "Model name:", _model_name);
        count += check_string(cpu_values.at(i), "Identifiant constructeur", "Vendor ID:", _constructor);
        count += check_string(cpu_values.at(i), "Vitesse maximale du processeur en MHz", "CPU max MHz:", _vmin);
        count += check_string(cpu_values.at(i), "Vitesse minimale du processeur en MHz", "CPU min MHz:", _vmax);
        count += check_string(cpu_values.at(i), "Processeur(s) :", "CPU(s)", _nb_cores);
        count += check_string(cpu_values.at(i), "Thread(s)", "Thread(s)", _nb_threads);
        count += check_string(cpu_values.at(i), "Vitesse du processeur en MHz", "CPU MHz:", _speed);
    }
    if (count != 9) {
        return (false);
    }
    return (true);
}

bool Processor::refresh()
{
    std::string cmd = "lscpu > tmp_file_cpu_values0.txt";
    std::system(cmd.c_str());
    std::vector<std::string> cpu_values = getSysFile("tmp_file_cpu_values0.txt");

    std::system("rm tmp_file_cpu_values0.txt");
    calc_cpu_usage();
    for (unsigned int i = 0; i < cpu_values.size(); i++) {
        if (check_string(cpu_values.at(i), "Vitesse du processeur en MHz", "CPU MHz:", _speed))
            return (true);
    }
    return (false);
}

void Processor::calc_cpu_usage()
{
    std::string cmd = "mpstat > tmp_file_cpu_values1.txt";
    std::system(cmd.c_str());
    std::vector<std::string> cpu_values = getSysFile("tmp_file_cpu_values1.txt", 1, 3);

    std::system("rm tmp_file_cpu_values1.txt");
    if (cpu_values.size() == 0)
        return;
    std::string str = cpu_values.at(0);
    float tmp = 0;
    int i = 0;
    int j;
    if (str.size() == 0)
        return;
    while (str[i] != ' ')
        i++;
    while (str[i] == ' ')
        i++;
    while (str[i] != ' ')
        i++;
    while (str[i] == ' ')
        i++;
    while (str[i]) {
        if (str[i] != ' ') {
            j = i;
            while (str[j] && str[j] != ' ')
                j++;
            if (str[j])
                tmp += std::strtof((str.substr(i, j - i)).c_str(), NULL);
            i = j;
        }
        else
            i++;
    }
    _usage = tmp;
    values_storage.push_back(tmp);
    while (values_storage.size() > 60)
        values_storage.erase(values_storage.begin());
}

/* GETTERS */
std::string Processor::getArchitecture() const
{
    return (_architecture);
}

std::string Processor::getBoutism() const
{
    return (_boutism);
}

std::string Processor::getModelName() const
{
    return (_model_name);
}

std::string Processor::getConstructor() const
{
    return (_constructor);
}

int Processor::getSpeed() const
{
    return (_speed);
}

int Processor::getUsage() const
{
    return (_usage);
}

int Processor::getVMin() const
{
    return (_vmin);
}

int Processor::getVMax() const
{
    return (_vmax);
}

int Processor::getNbCores() const
{
    return (_nb_cores);
}

int Processor::getNbThreads() const
{
    return (_nb_threads);
}

char Processor::getCommandDisplay() const
{
    return (this->_commandHide);
}

std::vector<int> Processor::getDataVect() const
{
    return (values_storage);
}

void Processor::setCommandDisplay(char command)
{
    this->_commandHide = command;
}

bool Processor::isDisplay() const
{
    return (this->_display);
}

void Processor::setDislay(bool display)
{
    this->_display = display;
}