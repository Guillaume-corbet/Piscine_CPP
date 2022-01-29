/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** revue
*/

#include "Object/Object.hpp"
#include "Object/Toy.hpp"
#include "Object/LittlePony.hpp"
#include "Object/Teddy.hpp"
#include "Box/Box.hpp"
#include "Box/GiftPaper.hpp"
#include "Box/Wrap.hpp"
#include "Carpet/IconveyorBelt.hpp"
#include "Carpet/Itable.hpp"
#include "Carpet/PapaXmasConveyorBelt.hpp"
#include "Carpet/PapaXmasTable.hpp"
#include "Carpet/create.hpp"
#include "Elf/PapaXmasElf.hpp"

void ex00()
{
    LittlePony poney("poney");
    Teddy nounours("nounours");

    std::cout << "\033[1;33m----Toy and Object----\033[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "LittlePony.isTaken()" << std::endl;
    poney.isTaken();
    std::cout << std::endl << "Teddy.isTaken()" << std::endl;
    nounours.isTaken();
    std::cout << std::endl;
}

void ex01()
{
    LittlePony poney("poney");
    Teddy nounours("nounours");
    Box boite;
    GiftPaper papier;

    std::cout << "\033[1;33m----Wrap----\033[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "WrapMeThat() boite" << std::endl;
    boite.wrapMeThat(&poney);
    std::cout << boite.getObject()->getTitle() << std::endl << std::endl;
    std::cout << "WrapMeThat() GirtPaper" << std::endl;
    papier.wrapMeThat(&nounours);
    std::cout << papier.getObject()->getTitle() << std::endl << std::endl;
}

void ex02()
{
    Box *boite = new Box();
    LittlePony poney("poney");
    Itable *table = createTable();
    IconveyorBelt *chaine = createConvoyerBelt();
    Wrap *wrap;

    std::cout << "\033[1;33m----Table/Convoyer----\033[0m" << std::endl;
    std::cout << std::endl;
    table->put(&poney);
    chaine->in(boite);
    std::cout << "Wrap In" << std::endl;
    wrap = chaine->take();
    wrap->wrapMeThat(table->take(0));
    chaine->put(wrap);
    chaine->out();
    std::cout << "Wrap Out" << std::endl;
}

void ex03()
{
    //Itable *table = createTable();
    IconveyorBelt *chaine = createConvoyerBelt();
    PapaXmasTable *theTable = new PapaXmasTable();
    ConveyorBeltRand rd_obj;

    std::cout << "\033[1;33m----Elf----\033[0m" << std::endl;
    std::cout << std::endl;
    rd_obj.randObject(theTable);
    rd_obj.randObject(theTable);
    PapaXmasElf elf(theTable, (PapaXmasConveyorBelt *)chaine);
    elf.createAGift();
}

int main(void)
{
    ex00();
    getchar();
    ex01();
    getchar();
    ex02();
    //getchar();
    //ex03();
}