// mx_strlen.c :: Ivan Ryzhenko 2021

#include "common.h"

unsigned int mx_strlen(const char *str) {
    const char *str_p = str;

    while (*str_p) {
        str_p++;
    };

    return (int)(str_p - str);
}
