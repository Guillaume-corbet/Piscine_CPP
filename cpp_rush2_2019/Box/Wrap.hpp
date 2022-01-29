/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include <iostream>
#include "../Object/Object.hpp"

class Wrap: public Object {
	public:
		Wrap();
		~Wrap();
        void openMe();
        void closeMe();
        void wrapMeThat(const Object *object);
        bool isOpen();
        bool isFull();
        const Object *getObject();
        Wrap &operator=(const Wrap &cur);

	protected:
        void setObject(const Object *obj);

	private:
        const Object *_object;
        bool _isOpen;
};

#endif /* !WRAP_HPP_ */