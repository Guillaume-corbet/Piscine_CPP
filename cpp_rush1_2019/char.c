/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static void Char_dtor(CharClass *this)
{

}

static char *Char_str(CharClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("No class");
    str = malloc(sizeof(char) * this->base.__size__);
    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<%s (%c)>", this->base.__name__, this->x);
    return (str);
}

static Class *Char_add(CharClass *ptr1, CharClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Char, ptr1->x + ptr2->x);
    return (result);
}

static Class *Char_sub(CharClass *ptr1, CharClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Char, ptr1->x - ptr2->x);
    return (result);
}

static Class *Char_mul(CharClass *ptr1, CharClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Char, ptr1->x * ptr2->x);
    return (result);
}

static Class *Char_div(CharClass *ptr1, CharClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Char, ptr1->x / ptr2->x);
    return (result);
}

static bool Char_eq(CharClass *ptr1, CharClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x == ptr2->x);
}

static bool Char_lt(CharClass *ptr1, CharClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x < ptr2->x);
}

static bool Char_gt(CharClass *ptr1, CharClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x > ptr2->x);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;