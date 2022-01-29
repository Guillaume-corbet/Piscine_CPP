/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->Fingerprint = random();
    this->Exp = 0;
}

DroidMemory::DroidMemory(size_t exp, size_t fingerprint)
{
    this->Fingerprint = fingerprint;
    this->Exp = exp;
}

DroidMemory::~DroidMemory()
{

}

size_t DroidMemory::getFingerprint() const
{
    return (this->Fingerprint);
}

void DroidMemory::setFingerprint(size_t fingerPrint)
{
    this->Fingerprint = fingerPrint;
}

size_t DroidMemory::getExp() const
{
    return (this->Exp);
}

void DroidMemory::setExp(size_t exp)
{
    this->Exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &tmp)
{
    this->Exp = this->Exp + tmp.Exp;
    this->Fingerprint = this->Fingerprint^tmp.Fingerprint;
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &tmp)
{
    tmp.Exp = tmp.Exp + this->Exp;
    tmp.Fingerprint = tmp.Fingerprint^this->Fingerprint;
    return (*this);
}

DroidMemory &DroidMemory::operator+=(DroidMemory &tmp)
{
    this->Exp = this->Exp + tmp.Exp;
    this->Fingerprint = this->Fingerprint^tmp.Fingerprint;
    return (*this);
}

DroidMemory &DroidMemory::operator+=(size_t tmp)
{
    this->Exp = this->Exp + tmp;
    this->Fingerprint = tmp^this->Fingerprint;
    return (*this);
}

DroidMemory &DroidMemory::operator+(DroidMemory &tmp)
{
    DroidMemory *dm;
    size_t exp = this->Exp + tmp.Exp;
    size_t fingerPrint = this->Fingerprint^tmp.Fingerprint;

    dm = new DroidMemory(exp, fingerPrint);
    return (*dm);
}

DroidMemory &DroidMemory::operator+(size_t tmp)
{
    DroidMemory *dm;
    size_t exp = this->Exp + tmp;
    size_t fingerPrint = this->Fingerprint^tmp;

    dm = new DroidMemory(exp, fingerPrint);
    return (*dm);
}

bool DroidMemory::operator==(DroidMemory &tmp) const
{
    if (this->Exp == tmp.Exp && this->Fingerprint == tmp.Fingerprint)
        return (true);
    return (false);
}

bool DroidMemory::operator!=(DroidMemory &tmp) const
{
    if (this->Exp == tmp.Exp && this->Fingerprint == tmp.Fingerprint)
        return (false);
    return (true);
}

bool DroidMemory::operator<(DroidMemory &tmp) const
{
    if  (this->Exp < tmp.Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<(size_t tmp) const
{
    if  (this->Exp < tmp)
        return (true);
    return (false);
}

bool DroidMemory::operator>(DroidMemory &tmp) const
{
    if  (this->Exp > tmp.Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>(size_t tmp) const
{
    if  (this->Exp > tmp)
        return (true);
    return (false);
}

bool DroidMemory::operator<=(DroidMemory &tmp) const
{
    if  (this->Exp <= tmp.Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<=(size_t tmp) const
{
    if  (this->Exp <= tmp)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(DroidMemory &tmp) const
{
    if  (this->Exp >= tmp.Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(size_t tmp) const
{
    if  (this->Exp >= tmp)
        return (true);
    return (false);
}

std::ostream &operator<<(std::ostream &s, const DroidMemory &tmp)
{
    s << "DroidMemory '" << tmp.getFingerprint() << "', " << tmp.getExp();
    return (s);
}