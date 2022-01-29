/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#pragma once

#include <string>
#include <iostream>
#include <stack>

class Parser {
	public:
		Parser();
		~Parser();
        void feed(const std::string &str);
        int result() const;
        void reset();
	protected:
	private:
        int _result;
        std::stack <int> _number;
        std::stack <char> _operator;
};