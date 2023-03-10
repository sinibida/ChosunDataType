#include <stdio.h>
#include <time.h>

void hanoi_print(int n, int** towers) {
    int width = n * 3 + 3;
    for (int i = 0; i < width; i++) {
        printf("=");
    }
    printf("\n");

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 3; x++) {
            int size = towers[x][y];
            for (int i = 0; i < n; i++) {
                if (i < size)
                    printf("@");
                else
                    printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }

    for (int i = 0; i < width; i++) {
        printf("=");
    }
    printf("\n");
}

int hanoi_get_top(int n, int* tower) {
    int top = 0;
    while (tower[top] == 0 && top < n) {
        top++;
    }
    return top;
}

void hanoi_move(int n, int** towers, int from, int to) {
    int* from_p = towers[from];
    int* to_p = towers[to];
    int from_top = hanoi_get_top(n, from_p);
    int to_top = hanoi_get_top(n, to_p) - 1;

    to_p[to_top] = from_p[from_top];
    from_p[from_top] = 0;

    printf("[%c -> %c]\n", 'A' + from, 'A' + to);
    hanoi_print(n, towers);
}

void hanoi_adv(int nn, int n, int** towers, int from, int temp, int to) {
    if (n == 1) {
        hanoi_move(nn, towers, from, to);
    } else {
        hanoi_adv(nn, n - 1, towers, from, to, temp);
        hanoi_move(nn, towers, from, to);
        hanoi_adv(nn, n - 1, towers, temp, from, to);
    }
}

#define HEIGHT 5

int main() {
    int a[HEIGHT], b[HEIGHT], c[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        a[i] = i + 1;
        b[i] = 0;
        c[i] = 0;
    }
    int* parr[3] = {a, b, c};

    hanoi_adv(HEIGHT, HEIGHT, parr, 0, 1, 2);

    return 0;
}
