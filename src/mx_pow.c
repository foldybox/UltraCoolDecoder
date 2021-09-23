// mx_pow.c

int mx_pow(int n, unsigned int pow) {
    int initial = n;

    if (pow == 0) {
        return 1;
    }
    for (unsigned int i = 1; i < pow; i++) {
        n *= initial;
    }

    return n; 
}
