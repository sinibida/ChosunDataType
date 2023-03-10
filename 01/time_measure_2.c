#include <stdio.h>
#include <time.h>

int main() {
    time_t start = time(NULL);

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

    time_t end = time(NULL);
    double duration = (double) difftime(end, start);
    printf("Foo       : %d\n", foo);
    printf("Time taken: %lf\n", duration);
}
