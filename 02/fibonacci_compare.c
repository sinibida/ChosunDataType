#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci_iter(int n) {
    int a = 1, b = 1, temp;
    for (int i = 2; i < n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    clock_t begin, end;

    begin = clock();
    printf("[Recursion]\n");
    printf("3th = %d\n", fibonacci(3));
    printf("15th = %d\n", fibonacci(15));
    printf("40th = %d\n", fibonacci(40));
    end = clock();
    printf("Time elapsed: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    printf("\n");

    begin = clock();
    printf("[Iteration]\n");
    printf("3th = %d\n", fibonacci_iter(3));
    printf("15th = %d\n", fibonacci_iter(15));
    printf("40th = %d\n", fibonacci_iter(40));
    end = clock();
    printf("Time elapsed: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    return 0;
}
