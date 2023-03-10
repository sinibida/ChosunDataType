#include <stdio.h>
#include <time.h>

void hanoi_print(int n, char from, char to) {
    printf("Plate %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char from, char temp, char to) {
    if (n == 1) {
        hanoi_print(n, from, to);
    } else {
        hanoi(n - 1, from, to, temp);
        hanoi_print(n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}

int main() {
    hanoi(4, 'A', 'B', 'C');

    return 0;
}
