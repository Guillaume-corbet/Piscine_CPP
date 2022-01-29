/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#pragma once

#include <string>
#include <iostream>

class Object {
	public:
		Object(const std::string &title, const std::string &type);
		~Object();
        virtual void isTaken() const;
        const std::string getTitle() const;
        void setObject(Object *ptr);
        void setType(const std::string &type);
        std::string getType();

	protected:
	private:
        const std::string _title;
        Object *_into;
        std::string _type;
};