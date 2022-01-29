/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <string>
#include <iostream>

class KreogCom {
	public:
		KreogCom(int x, int y, int serial);
		~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;
	private:
        const int m_serial;
        const int _x;
        const int _y;
        KreogCom *_ptr;
};

#endif /* !KREOGCOM_HPP_ */
