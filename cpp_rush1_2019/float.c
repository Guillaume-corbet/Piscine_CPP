/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg((*args), double);
}

static void Float_dtor(FloatClass *this)
{

}

static char *Float_str(FloatClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("No class");
    str = malloc(sizeof(char) * this->base.__size__);
    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<%s (%f)>", this->base.__name__, this->x);
    return (str);
}

static Class *Float_add(FloatClass *ptr1, FloatClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Float, ptr1->x + ptr2->x);
    return (result);
}

static Class *Float_sub(FloatClass *ptr1, FloatClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Float, ptr1->x - ptr2->x);
    return (result);
}

static Class *Float_mul(FloatClass *ptr1, FloatClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Float, ptr1->x * ptr2->x);
    return (result);
}

static Class *Float_div(FloatClass *ptr1, FloatClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Float, ptr1->x / ptr2->x);
    return (result);
}

static bool Float_eq(FloatClass *ptr1, FloatClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x == ptr2->x);
}

static bool Float_lt(FloatClass *ptr1, FloatClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x < ptr2->x);
}

static bool Float_gt(FloatClass *ptr1, FloatClass *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    return (ptr1->x > ptr2->x);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;