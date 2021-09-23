// mx_strdel.c :: Ivan Ryzhenko

#include <stdlib.h>
#include <stddef.h>

void mx_strdel(char **str) {
    if ((*str == NULL) || (str == NULL)) return;
    free(*str);
    *str = NULL;
}
