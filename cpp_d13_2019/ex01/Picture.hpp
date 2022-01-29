/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Picture {
	public:
        Picture();
		Picture(const std::string &file);
        Picture(const Picture &img);
		~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(const Picture &img);
	protected:
	private:
};