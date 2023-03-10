#include <stdio.h>
#include <time.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    printf("5! = %d\n", factorial(5));
    printf("10! = %d\n", factorial(10));

    return 0;
}
