// raise_error.c

#include "common.h"

void raise_error(t_error error, char *arg) {
    switch (error) {

    case INVALID_ARGUMENTS_COUNT: {
        char *error_str = "usage: ./ucd [operand1] [operation] [operand2] [result]\n";
        write(2, error_str, mx_strlen(error_str));
        exit(-1);
    } break;

    case INVALID_OPERATION: {
        char *str = mx_strjoin("Invalid operation: ", arg);
        char *error_str = mx_strjoin(str, "\n");
        write(2, error_str, mx_strlen(error_str));
        free(str);
        free(error_str);
        exit(-1);
    } break;

    case INVALID_OPERAND: {
        char *str = mx_strjoin("Invalid operand: ", arg);
        char *error_str = mx_strjoin(str, "\n");
        write(2, error_str, mx_strlen(error_str));
        free(str);
        free(error_str);
        exit(-1);
    } break;

    case INVALID_RESULT: {
        char *str = mx_strjoin("Invalid result: ", arg);
        char *error_str = mx_strjoin(str, "\n");
        write(2, error_str, mx_strlen(error_str));
        free(str);
        free(error_str);
        exit(-1);
    } break;

    case MEMORY_ERROR: {
        char *error_str = "Memory error: Null pointer\n";
        write(2, error_str, mx_strlen(error_str));
        exit(-1);
    } break;

    case DIVIDED_BY_ZERO: {
        char *error_str = "Calculation error: Divided by zero\n";
        write(2, error_str, mx_strlen(error_str));
        exit(-1);
    } break;

    default: {
        char *error_str = "Unknown error\n";
        write(2, error_str, mx_strlen(error_str));
        exit(-1);
    } break;

    }
}
