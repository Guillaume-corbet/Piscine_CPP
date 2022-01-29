/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->working_status = false;
    std::cout << "Dr." << name << ": I'm Dr." << name <<
    "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{

}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::ofstream file;
    std::string filename = (*patient).getName() + ".report";
    std::vector<std::string> drug;
    size_t pos = random()% 5;

    drug.push_back("Mars");
    drug.push_back("Buronzand");
    drug.push_back("Viagra");
    drug.push_back("Extasy");
    drug.push_back("Eucalyptus leaf");
    file.open(filename);
    std::cout << "Dr." << this->name << ": So what's goerking you Mr."
    << (*patient).getName() << "?" << std::endl;
    (*patient).poke();
    file << drug.at(pos);
    file.close();
}

void KoalaDoctor::timeCheck()
{
    if (this->working_status == false)
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
    else
        std::cout << "Dr." << this->name <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
    this->working_status = !this->working_status;
}

std::string KoalaDoctor::getName()
{
    return (this->name);
}
