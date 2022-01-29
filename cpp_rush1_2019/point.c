/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
{

}

static char *Point_str(PointClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("No class");
    str = malloc(sizeof(char) * this->base.__size__);
    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return (str);
}

static Class *Point_add(PointClass *ptr1, PointClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Point, ptr1->x + ptr2->x, ptr1->y + ptr2->y);
    return (result);
}

static Class *Point_sub(PointClass *ptr1, PointClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Point, ptr1->x - ptr2->x, ptr1->y - ptr2->y);
    return (result);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;