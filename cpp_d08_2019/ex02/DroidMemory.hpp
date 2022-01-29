/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>

class DroidMemory {
	public:
		DroidMemory();
        DroidMemory(size_t exp, size_t fingerprint);
		~DroidMemory();
        size_t getFingerprint() const;
        void setFingerprint(size_t fingerPrint);
        size_t getExp() const;
        void setExp(size_t exp);
        DroidMemory &operator<<(DroidMemory &tmp);
        DroidMemory &operator>>(DroidMemory &tmp);
        DroidMemory &operator+=(DroidMemory &tmp);
        DroidMemory &operator+=(size_t tmp);
        DroidMemory &operator+(DroidMemory &tmp);
        DroidMemory &operator+(size_t tmp);
        bool operator==(DroidMemory &tmp) const;
        bool operator!=(DroidMemory &tmp) const;
        bool operator<(DroidMemory &tmp) const;
        bool operator<(size_t tmp) const;
        bool operator>(DroidMemory &tmp) const;
        bool operator>(size_t tmp) const;
        bool operator<=(DroidMemory &tmp) const;
        bool operator<=(size_t tmp) const;
        bool operator>=(DroidMemory &tmp) const;
        bool operator>=(size_t tmp) const;
	private:
        size_t Fingerprint;
        size_t Exp;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &tmp);

#endif /* !DROIDMEMORY_HPP_ */
