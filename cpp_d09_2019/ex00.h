/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cthulhu_s
{
    char *m_name;
    int m_power;
    void (*print_power)(struct cthulhu_s *thi);
    void (*attack)(struct cthulhu_s *thi);
    void (*sleeping)(struct cthulhu_s *thi);
}cthulhu_t;

typedef struct koala_s
{
    cthulhu_t m_parent;
    char m_is_a_legend;
    void (*eat)(struct koala_s *thi);
}koala_t;

cthulhu_t *new_cthulhu(void);
void print_power(cthulhu_t *thi);
void attack(cthulhu_t *thi);
void sleeping(cthulhu_t *thi);
//static void cthulhu_initializer(cthulhu_t *thi);

koala_t *new_koala(char *name, char is_a_legend);
void eat(koala_t *thi);
//static void koala_initializer(koala_t *thi, char *_name, char _is_A_Legend);

#endif /* !EX00_H_ */
