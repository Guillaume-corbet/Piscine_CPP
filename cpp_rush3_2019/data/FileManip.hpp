/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** FileManip
*/

#ifndef FILEMANIP_HPP_
#define FILEMANIP_HPP_

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> getSysFile(const std::string filePath);
std::vector<std::string> getSysFile(const std::string filePath, int len);
std::vector<std::string> getSysFile(const std::string filePath, int len, int pos);
std::string getFile(const std::string filePath);

#endif /* !FILEMANIP_HPP_ */