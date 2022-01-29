/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** Hospital
*/

#include "Hospital.hpp"

Hospital::Hospital()
{
    this->doctor = NULL;
    this->nurse = NULL;
    this->sick = NULL;
}

Hospital::~Hospital()
{

}

void Hospital::addDoctor(KoalaDoctorList *doctor)
{
    if (this->doctor == NULL)
        this->doctor = doctor;
    else if (this->doctor->getFromName(doctor->getContent()->getName()) == NULL)
        this->doctor->append(doctor);
}

void Hospital::addSick(SickKoalaList *sick)
{
    if (this->sick == NULL)
        this->sick = sick;
    else if (this->sick->getFromName(sick->getContent()->getName()) == NULL)
        this->sick->append(sick);
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (this->nurse == NULL)
        this->nurse = nurse;
    else if (this->nurse->getFromID(nurse->getContent()->getID()) == NULL)
        this->nurse->append(nurse);
}

void Hospital::doctorStart()
{
    KoalaDoctorList *tmp = this->doctor;

    while (tmp != NULL) {
        std::cout << "[HOSPITAL] Doctor " << tmp->getContent()->getName() << " just arrived!" << std::endl;
        tmp->getContent()->timeCheck();
        tmp = tmp->getNext();
    }
}

void Hospital::nurseStart()
{
    KoalaNurseList *tmp = this->nurse;

    while (tmp != NULL) {
        std::cout << "[HOSPITAL] Nurse " << tmp->getContent()->getID() << " just arrived!" << std::endl;
        tmp->getContent()->timeCheck();
        tmp = tmp->getNext();
    }
}

void Hospital::sickStart()
{
    SickKoalaList *tmp = this->sick;

    while (tmp != NULL) {
        std::cout << "[HOSPITAL] Patient " << tmp->getContent()->getName() << " just arrived!" << std::endl;
        tmp = tmp->getNext();
    }
}

void Hospital::hospitalStart()
{
    this->doctorStart();
    this->sickStart();
    this->nurseStart();
    std::cout << "[HOSPITAL] Work starting with:" << std::endl << std::endl;
    this->doctor->dump();
    this->nurse->dump();
    this->sick->dump();
}

void Hospital::doctorEnd()
{
    KoalaDoctorList *tmp = this->doctor;

    while (tmp != NULL) {
        tmp->getContent()->timeCheck();
        tmp = tmp->getNext();
        tmp = tmp->remove(tmp);
        this->doctor = tmp;
    }
}

void Hospital::sickEnd()
{
    SickKoalaList *tmp = this->sick;

    while (tmp != NULL) {
        tmp = tmp->remove(tmp);
        this->sick = tmp;
    }
}

void Hospital::nurseEnd()
{
    KoalaNurseList *tmp = this->nurse;

    while (tmp != NULL) {
        tmp->getContent()->timeCheck();
        tmp = tmp->remove(tmp);
        this->nurse = tmp;
    }
}

void Hospital::hospitalEnd()
{
    this->nurseEnd();
    this->doctorEnd();
    this->sickEnd();
}

void Hospital::hospitalTraitment()
{
    KoalaDoctorList *tmp_doctor = this->doctor;
    KoalaNurseList *tmp_nurse = this->nurse;
    SickKoalaList *tmp_sick = this->sick;
    std::string drug;

    while (tmp_sick != NULL) {
        if (tmp_doctor == NULL)
            tmp_doctor = this->doctor;
        if (tmp_nurse == NULL)
            tmp_nurse = this->nurse;
        tmp_doctor->getContent()->diagnose(tmp_sick->getContent());
        drug = tmp_nurse->getContent()->readReport(tmp_sick->getContent()->getName() + ".report");
        tmp_nurse->getContent()->giveDrug(drug, tmp_sick->getContent());
        tmp_doctor = tmp_doctor->getNext();
        tmp_nurse = tmp_nurse->getNext();
        tmp_sick = tmp_sick->getNext();
    }
}

void Hospital::run()
{
    this->hospitalStart();
    this->hospitalTraitment();
    this->hospitalEnd();
}