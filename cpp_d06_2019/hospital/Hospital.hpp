/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include  <iostream>
#include  <string>
#include  <cstdlib>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"
#include "SickKoalaList.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctorList.hpp"

class Hospital {
	public:
		Hospital();
		~Hospital();
        void addDoctor(KoalaDoctorList *doctor);
        void addSick(SickKoalaList *sick);
        void addNurse(KoalaNurseList *nurse);
        void run();
	protected:
	private:
        KoalaDoctorList *doctor;
        SickKoalaList *sick;
        KoalaNurseList *nurse;
        void doctorStart();
        void nurseStart();
        void sickStart();
        void hospitalStart();
        void doctorEnd();
        void nurseEnd();
        void sickEnd();
        void hospitalEnd();
        void hospitalTraitment();
};

#endif /* !HOSPITAL_HPP_ */
