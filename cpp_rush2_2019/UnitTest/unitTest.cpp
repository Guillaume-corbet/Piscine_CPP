/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** unitTest
*/

// En vrai tu pense que sur un malentendue ?

#include "unitTest.hpp"

Object *MyUnitTests(Object **box)
{
    box[1]->wrapMeThat(box[0]);
    box[2]->wrapMeThat(box[1]);
}

Object **MyUnitTests()
{
    Object **kdo = new (Object*);
    Object **box = new (Object*);

    box[0] = new Teddy("Teddy");
    box[1] = new Box();
    box[2] = new GiftPaper();

    box[2] = MyUnitTests(box);

    kdo[0] = new LittlePony("happy pony");
    kdo[1] = new Teddy("cuddles");
    return(kdo);
}

int main(void)
{
    Object **kdo;

    kdo = MyUnitTests();
    //MyUnitTests(kdo);
    delete(kdo[0]);
    delete(kdo[1]);
    delete(kdo);
}