// mx_printint.c :: Ivan Ryzhenko 2021

#include "common.h"

void mx_printint(int n) {
    int _n = n;
    int len = 0;
    int counter = 1;

    if (n == 0) {
        write(1, "0", 1);
        return;
    }
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        write(1, "-", 1);
        n *= -1;
        _n *= -1;
    }

    while (_n != 0) {
        len++;
        _n = _n / 10;
    }
    for (int i = 0; i < len - 1; i++) {
        counter *= 10;
    }
    for (int i = 0; i < len; i++) {
        char c = (n / counter) + 48;
        write(1, &c, 1);
        n -= counter * (n / counter);
        counter /= 10;
    }
}
