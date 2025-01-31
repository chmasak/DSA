#include <stdio.h>

// Swap functions that swaps
// two values
int valswap(int x, int y) {
    int t;
    t = x;
    x = y;
    y = t;
    return x,y;
}
int refswap(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
    return *x,*y;
}

// Main function
int main() {
    int a = 10, b = 20;

    // Pass by Values
    printf("Original values: a = %d b = %d\n", a, b);
    valswap(a, b);
    printf("After call by value: a = %d b = %d\n", a, b);
    refswap(&a, &b);
    printf("After call by value: a = %d b = %d\n", a, b);
    return 0;
}
