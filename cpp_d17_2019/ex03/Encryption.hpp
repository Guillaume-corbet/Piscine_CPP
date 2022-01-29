/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include "IEncryptionMethod.hpp"
#include <functional>
#include <string>
#include <iostream>
#include <algorithm>

class Encryption{
	public:
		Encryption(IEncryptionMethod& encryptionMethod, void (IEncryptionMethod::*func)(char plainchar));
		~Encryption();
        Encryption operator()(char toCrypt);
        static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt);
        
	protected:
	private:
        void (IEncryptionMethod::*func)(char plainchar);
        IEncryptionMethod *encryptionMethod;
};

#endif /* !ENCRYPTION_HPP_ */
