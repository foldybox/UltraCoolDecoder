// args_handler.c

#include "common.h"

// Allocate memory for args
void args_allocate_memory(t_args *args, char *argv[]) {
    args->operand1_size = mx_pow(10.0, mx_count_of_matches(argv[1], '?'));
    args->operand1_arr = (int *) malloc(args->operand1_size * sizeof(int));
    if (args->operand1_arr == NULL) raise_error(MEMORY_ERROR, NULL);

    args->operand2_size = mx_pow(10.0, mx_count_of_matches(argv[3], '?'));
    args->operand2_arr = (int *) malloc(args->operand2_size * sizeof(int));
    if (args->operand2_arr == NULL) raise_error(MEMORY_ERROR, NULL);

    args->result_size = mx_pow(10.0, mx_count_of_matches(argv[4], '?'));
    args->result_arr = (int *) malloc(args->result_size * sizeof(int));
    if (args->result_arr == NULL) raise_error(MEMORY_ERROR, NULL);

    args->operator_size = mx_count_of_matches(argv[2], '?') > 0 ? 4 : 1;
    args->operator_arr = (t_operator *) malloc(args->operator_size * sizeof(t_operator));
    if (args->operator_arr == NULL) raise_error(MEMORY_ERROR, NULL);
}

// Parse integer values into args array
bool args_parse_int(char *str, int *arr, int size) {
    int prev_count = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    for (int i = mx_strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        if (mx_isdigit(str[i])) {
            for (int k = 0; k < size; k++) {
                arr[k] += ((str[i] - 48) * mx_pow(10, j));
            }
        }
        else if (str[i] == '?') {
            for (int k = 0, n = 0; k < size; k++) {
                if (n > 9) n = 0;
                arr[k] += (n * mx_pow(10, j));

                if (k % mx_pow(10, prev_count) == 0) n++;
            }
            prev_count++;
        }
        else if (str[i] == '-') {
            for (int k = 0; k < size; k++) {
                arr[k] *= -1;
            }
            return true;
        }
        else return false;
    }

    return true;
}

// Parse operator values into args array
bool args_parse_operator(char *str, t_operator *arr) {
    if (mx_strlen(str) > 1) return false;

    if (str[0] == '?') {
        arr[0] = ADD;
        arr[1] = SUB;
        arr[2] = MUL;
        arr[3] = DIV;
    }
    else {
        switch (str[0])
        {
        case '+':
            arr[0] = ADD;
            break;
        case '-':
            arr[0] = SUB;
            break;
        case '*':
            arr[0] = MUL;
            break;
        case '/':
            arr[0] = DIV;
            break;
        default:
            return false;
            break;
        }
    }

    return true;
}

// Init args struct
t_args args_init(char *argv[]) {
    t_args ret;

    args_allocate_memory(&ret, argv);

    if (!args_parse_operator(mx_strtrim(argv[2]), ret.operator_arr)) raise_error(INVALID_OPERATION, argv[2]);
    if (!args_parse_int(mx_strtrim(argv[1]), ret.operand1_arr, ret.operand1_size)) raise_error(INVALID_OPERAND, argv[1]);
    if (!args_parse_int(mx_strtrim(argv[3]), ret.operand2_arr, ret.operand2_size)) raise_error(INVALID_OPERAND, argv[3]);
    if (!args_parse_int(mx_strtrim(argv[4]), ret.result_arr, ret.result_size)) raise_error(INVALID_RESULT, argv[4]);

    return ret;
}

// Calculate and print args
void args_calculation(t_args args) {
    for(int op = 0; op < args.operator_size; op++) {
        for(int i = 0; i < args.operand1_size; i++) {
            for(int j = 0; j < args.operand2_size; j++) {
                for(int r = 0; r < args.result_size; r++) {
                    switch (args.operator_arr[op]) {
                        case ADD:
                            if (args.operand1_arr[i] + args.operand2_arr[j] == args.result_arr[r]) {
                                mx_printint(args.operand1_arr[i]);
                                mx_printstr(" + ");
                                mx_printint(args.operand2_arr[j]);
                                mx_printstr(" = ");
                                mx_printint(args.result_arr[r]);
                                mx_printchar('\n');
                            }
                            break;

                        case SUB:
                            if (args.operand1_arr[i] - args.operand2_arr[j] == args.result_arr[r]) {
                                mx_printint(args.operand1_arr[i]);
                                mx_printstr(" - ");
                                mx_printint(args.operand2_arr[j]);
                                mx_printstr(" = ");
                                mx_printint(args.result_arr[r]);
                                mx_printchar('\n');
                            }
                            break;

                        case MUL:
                            if (args.operand1_arr[i] * args.operand2_arr[j] == args.result_arr[r]) {
                                mx_printint(args.operand1_arr[i]);
                                mx_printstr(" * ");
                                mx_printint(args.operand2_arr[j]);
                                mx_printstr(" = ");
                                mx_printint(args.result_arr[r]);
                                mx_printchar('\n');
                            }
                            break;

                        case DIV:
                            if (args.operand2_arr[j] != 0 
                                && args.operand1_arr[i] / args.operand2_arr[j] == args.result_arr[r]) {
                                mx_printint(args.operand1_arr[i]);
                                mx_printstr(" / ");
                                mx_printint(args.operand2_arr[j]);
                                mx_printstr(" = ");
                                mx_printint(args.result_arr[r]);
                                mx_printchar('\n');
                            }
                            break;

                        default:
                            raise_error(-1, NULL);
                            break;
                    }
                }
            }
        }
    }    
}

// Free args struct
void args_free(t_args *args) {
    if (args->operand1_arr != NULL) {
        free(args->operand1_arr);
        args->operand1_arr = NULL;
    }
    if (args->operand2_arr != NULL) {
        free(args->operand2_arr);
        args->operand2_arr = NULL;
    }
    if (args->result_arr != NULL) {
        free(args->result_arr);
        args->result_arr = NULL;
    }
    if (args->operator_arr != NULL) {
        free(args->operator_arr);
        args->operator_arr = NULL;
    }
}
