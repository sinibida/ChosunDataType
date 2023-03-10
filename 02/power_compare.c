#include <stdio.h>
#include <time.h>

double power(double x, int p) {
    if (p == 0)
        return 1;
    else if (p % 2 == 0)
        return power(x * x, p / 2);
    else
        return x * power(x * x, (p - 1) / 2);
}

double power_iter(double x, int p) {
    double v = 1.0;
    for (int i = 0; i < p; i++) v *= x;
    return v;
}

int main() {
    clock_t begin, end;
    double foo;

    begin = clock();
    printf("[Recursion]\n");
    for (int i = 0; i < 10000; i++) {
        foo = power(1.0001, 100000);
    }
    printf("1.0001^100000 = %lf\n", foo);
    end = clock();
    printf("Time elapsed: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    printf("\n");

    begin = clock();
    printf("[Iteration]\n");
    for (int i = 0; i < 10000; i++) {
        foo = power_iter(1.0001, 100000);
    }
    printf("1.0001^100000 = %lf\n", foo);
    end = clock();
    printf("Time elapsed: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    return 0;
}
