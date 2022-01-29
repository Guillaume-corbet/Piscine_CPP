/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"
#include <algorithm>

class OneTime : public IEncryptionMethod {
	public:
		OneTime(const std::string &key);
		~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();
	protected:
	private:
        std::string key;
        size_t move;
};

#endif /* !ONETIME_HPP_ */
