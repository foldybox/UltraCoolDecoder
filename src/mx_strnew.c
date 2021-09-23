// mx_strnew.c :: Ivan Ryzhenko 2021

#include "common.h"

char *mx_strnew(const int size) {
    char *ret = (char *)malloc(size * sizeof(char) + 1);
    if (ret == NULL) return NULL;

    for (int i = 0; i < size + 1; i++) {
        ret[i] = '\0';
    }
    
    return ret;
}
