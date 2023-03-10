#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    // Example of code
    long long foo = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 1000; k++) {
                foo++;
            }
        }
    }
    // Example of code

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Foo       : %d\n", foo);
    printf("Time taken: %lf\n", duration);
}
