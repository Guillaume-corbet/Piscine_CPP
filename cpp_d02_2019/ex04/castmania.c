/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** castmania
*/

#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *instr = data;

    if (instruction_type == ADD_OPERATION) {
        exec_add(data);
    } else if (instruction_type == DIV_OPERATION) {
        exec_div(data);
    }
}