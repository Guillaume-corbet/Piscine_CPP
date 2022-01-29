/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{

}

static char *Vertex_str(VertexClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("No class");
    str = malloc(sizeof(char) * this->base.__size__);
    if (str == NULL)
        raise("Out of memory");
    sprintf(str, "<%s (%d, %d, %d)>", this->base.__name__,
    this->x, this->y, this->z);
    return (str);
}

static Class *Vertex_add(VertexClass *ptr1, VertexClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Vertex, ptr1->x + ptr2->x, ptr1->y + ptr2->y,
    ptr1->z + ptr2->z);
    return (result);
}

static Class *Vertex_sub(VertexClass *ptr1, VertexClass *ptr2)
{
    Class *result;
    if (ptr1 == NULL || ptr2 == NULL)
        raise("Null Object");
    result = new(Vertex, ptr1->x - ptr2->x, ptr1->y - ptr2->y,
    ptr1->z - ptr2->z);
    return (result);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;