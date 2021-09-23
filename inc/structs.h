// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H


#include "enums.h"

typedef struct s_args {
    t_operator *operator_arr;
    int operator_size;

    int *operand1_arr;
    int operand1_size;

    int *operand2_arr;
    int operand2_size;

    int *result_arr;
    int result_size;
}              t_args;


#endif
