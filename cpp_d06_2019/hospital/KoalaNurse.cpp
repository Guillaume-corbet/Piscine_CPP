/*
** EPITECH PROJECT, 2020
** day6
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
    this->working_status = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string Drug, SickKoala *koala)
{
    (*koala).takeDrug(Drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file;
    std::string drugName("");

    file.open(filename);
    if (!file.is_open()) {
        return (drugName);
    }
    getline(file, drugName);
    filename.replace(filename.find(".report"), sizeof(".report") - 1, "");
    std::cout << "Nurse " << this->id << ": Kreog! Mr." << filename <<
    " needs a " << drugName << "!" << std::endl;
    file.close();
    return (drugName);
}

void KoalaNurse::timeCheck()
{
    if (this->working_status == false)
        std::cout << "Nurse " << this->id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse " << this->id <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
    this->working_status = !this->working_status;
}

int KoalaNurse::getID()
{
    return (this->id);
}