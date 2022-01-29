/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** file_manip
*/

#include "FileManip.hpp"

std::string getFile(const std::string filePath)
{
    std::ifstream fs;
	std::string data;
    std::string res;

	fs.open(filePath);
    if (fs.is_open()) {
        while (getline(fs, data)) {
            res.append(data);
        }
        fs.close();
        return (res);
    }
    return (res);
}

std::vector<std::string> getSysFile(const std::string filePath)
{
    std::ifstream fs;
	std::string data;
    std::vector<std::string> vect;

	fs.open(filePath);
    if (fs.is_open()) {
        while (getline(fs, data)) {
            vect.push_back(data);
        }
        fs.close();
        return (vect);
    }
    return (vect);
}

std::vector<std::string> getSysFile(const std::string filePath, int len)
{
    std::ifstream fs;
	std::string data;
    std::vector<std::string> vect;
    int i = 0;

	fs.open(filePath);
    if (fs.is_open()) {
        while (getline(fs, data) && i < len) {
            vect.push_back(data);
            i++;
        }
        fs.close();
        return (vect);
    }
    return (vect);
}

std::vector<std::string> getSysFile(const std::string filePath, int len, int pos)
{
    std::ifstream fs;
	std::string data;
    std::vector<std::string> vect;
    int i = 0;

	fs.open(filePath);
    if (fs.is_open()) {
        while (getline(fs, data) && i < len + pos) {
            if (i >= pos)
                vect.push_back(data);
            i++;
        }
        fs.close();
        return (vect);
    }
    return (vect);
}