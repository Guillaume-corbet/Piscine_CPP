/*
** EPITECH PROJECT, 2020
** cpp_d02_2019
** File description:
** castmania
*/

#include "castmania.h"
#include <stdio.h>

void check_type(division_t *div)
{
    integer_op_t *integer;
    decimale_op_t *decimal;

    if (div->div_type == INTEGER) {
        integer = div->div_op;
        printf("%d\n", integer->res);
    } else if (div->div_type == DECIMALE) {
        decimal = div->div_op;
        printf("%f\n", decimal->res);
    }
}

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *instr = data;
    addition_t *add;
    division_t *div;

    if (instruction_type == ADD_OPERATION) {
        exec_add(instr->operation);
        if (instr->output_type == VERBOSE) {
            add = instr->operation;
            printf("%d\n", add->add_op.res);
        }
    } else if (instruction_type == DIV_OPERATION) {
        exec_div(instr->operation);
        if (instr->output_type == VERBOSE) {
            div = instr->operation;
            check_type(div);
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    int *tmp;
    float *tmp2;

    if (instruction_type == PRINT_INT) {
        tmp = data;
        printf("%d\n", *tmp);
    } else if (instruction_type == PRINT_FLOAT) {
        tmp2 = data;
        printf("%f\n", *tmp2);
    } else {
        exec_operation(instruction_type, data);
    }
}