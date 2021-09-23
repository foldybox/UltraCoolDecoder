// mx_isdigit.c :: Ivan Ryzhenko 2021

#include "common.h"

bool mx_isdigit(int c) {
    if (48 <= c && c <= 57) {
        return true;
    }
    else {
        return false;
    }
}
