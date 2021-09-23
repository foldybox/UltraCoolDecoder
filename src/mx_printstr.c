// mx_printstr.c :: Ivan Ryzhenko 2021

#include "common.h"

void mx_printstr(const char *str) {
    write(1, str, mx_strlen(str));
}
