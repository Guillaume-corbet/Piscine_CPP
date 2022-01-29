/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex00
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *thi)
{
    thi->print_power = &print_power;
    thi->attack = &attack;
    thi->sleeping = &sleeping;
}

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));

    if (new == NULL)
        exit(84);
    new->m_name = strdup("Cthulhu");
    new->m_power = 42;
    cthulhu_initializer(new);
    printf("----\n");
    printf("Building %s\n", new->m_name);
    return (new);
}

void print_power(cthulhu_t *thi)
{
    printf("Power => %d\n", thi->m_power);
    return;
}

void attack(cthulhu_t *thi)
{
    if (thi->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n"
        , thi->m_name);
        return;
    }
    thi->m_power = thi->m_power - 42;
    printf("%s attacks and destroys the city\n", thi->m_name);
    return;

}

void sleeping(cthulhu_t *thi)
{
    printf("%s sleeps\n", thi->m_name);
    thi->m_power = thi->m_power + 42000;
    return;
}

static void koala_initializer(koala_t *thi, char *_name, char is_A_Legend)
{
    thi->eat = &eat;
    thi->m_is_a_legend = is_A_Legend;
    thi->m_parent = (*new_cthulhu());
    if (strlen(_name) > 0) {
        free(thi->m_parent.m_name);
        thi->m_parent.m_name = strdup(_name);
    }
    if (is_A_Legend == 0)
        thi->m_parent.m_power = 0;
    printf("Building %s\n", _name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    if (new == NULL)
        exit(84);
    koala_initializer(new, name, is_a_legend);
    return new;
}

void eat(koala_t *thi)
{
    printf("%s eats\n", thi->m_parent.m_name);
    thi->m_parent.m_power = thi->m_parent.m_power + 42;
    return;
}