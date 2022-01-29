/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    this->_result = 0;
}

Parser::~Parser()
{

}

int calc(int par, int nb, char op)
{
    if (op == '+')
        par = par + nb;
    else if (op == '-')
        par = par - nb;
    else if (op == '*')
        par = par * nb;
    else if (op == '/')
        par = par / nb;
    else if (op == '%')
        par = par % nb;
    return (par);
}

int parserRec(const std::string &str)
{
    size_t i = 0;
    size_t j = 0;
    int nb = 0;
    int par = 0;
    char op;
    std::string newStr = str;
    std::stack <int> _number;
    std::stack <char> _operator;
    std::stack <int> _numberRec;
    std::stack <char> _operatorRec;

    while (i < newStr.size()) {
        if (newStr.at(i) == '(') {
            par = par + 1;
            i = i + 1;
            j = i;
            while (par > 0) {
                if (newStr.at(i) == '(')
                    par = par + 1;
                else if (newStr.at(i) == ')')
                    par = par - 1;
                i = i + 1;
            }
            _number.push(parserRec(str.substr(j, i - j - 1)));
        } else if (i < newStr.size() && newStr.at(i) <= '9' && newStr.at(i) >= '0') {
            j = i;
            while (i < newStr.size() && newStr.at(i) <= '9' && newStr.at(i) >= '0')
                i = i + 1;
            _number.push(atoi(newStr.substr(j, i - j).c_str()));
        } else if (i < newStr.size() && (newStr.at(i) == '+' || newStr.at(i) == '-' || newStr.at(i) == '/' || newStr.at(i) == '%' || str.at(i) == '*')) {
            _operator.push(newStr.at(i));
            i = i + 1;
        } else
            i = i + 1;
    }
    while (_number.size() > 0) {
        _numberRec.push(_number.top());
        _number.pop();
    }
    while (_operator.size() > 0) {
        _operatorRec.push(_operator.top());
        _operator.pop();
    }
    par = _numberRec.top();
    _numberRec.pop();
    while (_numberRec.size() > 0) {
        op = _operatorRec.top();
        _operatorRec.pop();
        nb = _numberRec.top();
        _numberRec.pop();
        par = calc(par, nb, op);
    }
    return (par);
}

void Parser::feed(const std::string &str)
{
    size_t i = 0;
    size_t j = 0;
    int par = 0;
    int nb = 0;
    char op;
    std::string newStr = str;
    std::stack <int> _numberRec;
    std::stack <char> _operatorRec;

    while (i < newStr.size()) {
        if (newStr.at(i) == '(') {
            par = par + 1;
            i = i + 1;
            j = i;
            while (par > 0) {
                if (newStr.at(i) == '(')
                    par = par + 1;
                else if (newStr.at(i) == ')')
                    par = par - 1;
                i = i + 1;
            }
            this->_number.push(parserRec(str.substr(j, i - j - 1)));
        } else if (i < newStr.size() && (newStr.at(i) == '+' || newStr.at(i) == '-' || newStr.at(i) == '/' || newStr.at(i) == '%' || str.at(i) == '*')) {
            this->_operator.push(newStr.at(i));
            i = i + 1;        
        } else if (i < newStr.size() && newStr.at(i) <= '9' && newStr.at(i) >= '0') {
            j = i;
            while (i < newStr.size() && newStr.at(i) <= '9' && newStr.at(i) >= '0')
                i = i + 1;
            this->_number.push(atoi(newStr.substr(j, i - j).c_str()));
        } else
            i = i + 1;
    }
    while (_number.size() > 0) {
        _numberRec.push(_number.top());
        _number.pop();
    }
    while (_operator.size() > 0) {
        _operatorRec.push(_operator.top());
        _operator.pop();
    }
    par = _numberRec.top();
    _numberRec.pop();
    while (_numberRec.size() > 0) {
        op = _operatorRec.top();
        _operatorRec.pop();
        nb = _numberRec.top();
        _numberRec.pop();
        par = calc(par, nb, op);
    }
    _result = _result + par;
}

int Parser::result() const
{
    return (_result);
}

void Parser::reset()
{
    this->_result = 0;
}