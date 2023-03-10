#include <stdio.h>
#include <time.h>

int factorial(int n) {
    int v = 1;
    for (int i = 1; i <= n; i++) {
        v *= i;
    }
    return v;
}

int main() {
    printf("5! = %d\n", factorial(5));
    printf("10! = %d\n", factorial(10));

    return 0;
}
