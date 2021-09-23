// main.c

#include "common.h"

int main(int argc, char *argv[]) {

    if (argc != 5) raise_error(INVALID_ARGUMENTS_COUNT, NULL);
    
    t_args args = args_init(argv);

    args_calculation(args);

    args_free(&args);

    return 0;
}
