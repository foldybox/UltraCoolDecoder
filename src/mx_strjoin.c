// mx_strjoin.c :: Ivan Ryzhenko 2021

#include <stddef.h>

int mx_strlen(const char *);
char *mx_strnew(const int);
char *mx_strcpy(char *, const char *);

char *mx_strjoin(char const *s1, char const *s2) {
    unsigned int len = 0;
    unsigned int offset = 0;

    if ((s1 == NULL) && (s2 == NULL)) {
        return NULL;
    }
    if (s1 != NULL) {
        len += mx_strlen(s1);
        offset = mx_strlen(s1);
    }
    if (s2 != NULL) {
        len += mx_strlen(s2);
    }

    char *ret = mx_strnew(len);

    if (s1 != NULL) {
        mx_strcpy(ret, s1);
    }
    if (s2 != NULL) {
        mx_strcpy(ret + offset, s2);
    }

    return ret;
}
