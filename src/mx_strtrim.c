// mx_strtrim.c :: Ivan Ryzhenko 2021

#include "common.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;

    unsigned int offset_top = 0;
    unsigned int offset_bottom = 0;
    unsigned int len = mx_strlen(str);
    unsigned int len_new = 0;
    char *ret = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) offset_top++;
        else break;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (mx_isspace(str[i])) offset_bottom++;
        else break;
    }

    len_new = len - offset_bottom - offset_top;
    if (len_new < 0) len_new = 0;
    
    ret = mx_strnew(len_new);
    if (ret == NULL) return NULL;

    mx_strncpy(ret, str + offset_top, len_new);
    
    return ret;
}
