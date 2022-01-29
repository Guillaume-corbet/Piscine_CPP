/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

typedef union foo4
{
    short int bar;
    unsigned short foo;
}foo4_t;

typedef union foo3
{
    foo4_t bar;
    unsigned short foo;
}foo3_t;

typedef union foo2
{
    foo3_t bar;
    unsigned short foo;
    int xd;
}foo2_t;

typedef union foo1
{
    unsigned int bar;
    foo2_t foo;
}foo_t;

#endif /* !EX05_H_ */
