// enums.h
#ifndef ENUMS_H
#define ENUMS_H


typedef enum e_operator {
    ADD,
    SUB,
    MUL,
    DIV
} t_operator;

typedef enum e_error {
    INVALID_ARGUMENTS_COUNT,
    INVALID_OPERATION,
    INVALID_OPERAND,
    INVALID_RESULT,
    MEMORY_ERROR,
    DIVIDED_BY_ZERO
} t_error;


#endif
