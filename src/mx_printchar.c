// mx_printchar.c :: Ivan Ryzhenko 2021

#include "common.h"

void mx_printchar(char c) {
    write(1, &c, 1);
}
