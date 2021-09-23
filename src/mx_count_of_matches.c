// mx_count_of_matches.c

#include "common.h"

int mx_count_of_matches(char *str, char c) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) count++;
    }
    
    return count;
}
