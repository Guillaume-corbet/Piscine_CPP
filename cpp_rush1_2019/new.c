/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** new
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    va_list(ap);
    Class *obj;

    if (class == NULL)
        raise("No class");
    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    if (obj == NULL)
        raise("No object created");
    return (obj);
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *new_class = malloc(class->__size__);

    if (class == NULL)
        raise("No class");
    if (new_class == NULL)
        raise("Out of memory");
    memcpy(new_class, class, class->__size__);
    if (new_class->__ctor__)
        new_class->__ctor__(new_class, ap);
    return (new_class);
}

void delete(Object *ptr)
{
    Class *class = (Class *)ptr;

    if (ptr != NULL) {
        if (((Class *)ptr)->__dtor__)
            ((Class *)ptr)->__dtor__(ptr);
        free(ptr);
    }
}