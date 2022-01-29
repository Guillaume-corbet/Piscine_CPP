/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static void Int_dtor(IntClass *this)
{

}

static char *Int_str(IntClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("Null Object");
    str = malloc(sizeof(char) * this->base.__size__);
    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<%s (%d)>", this->base.__name__, this->x);
    return (str);
}

static Class *Int_add(IntClass *ptr1, IntClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Int, ptr1->x + ptr2->x);
    return (result);
}

static Class *Int_sub(IntClass *ptr1, IntClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Int, ptr1->x - ptr2->x);
    return (result);
}

static Class *Int_mul(IntClass *ptr1, IntClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Int, ptr1->x * ptr2->x);
    return (result);
}

static Class *Int_div(IntClass *ptr1, IntClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Int, ptr1->x / ptr2->x);
    return (result);
}

static bool Int_eq(IntClass *ptr1, IntClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x == ptr2->x);
}

static bool Int_lt(IntClass *ptr1, IntClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x < ptr2->x);
}

static bool Int_gt(IntClass *ptr1, IntClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x > ptr2->x);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;