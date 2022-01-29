/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator do_find(T &check, int nb)
{
    return (std::find(check.begin(), check.end(), nb));
}

#endif /* !FIND_HPP_ */