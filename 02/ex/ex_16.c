#include <stdio.h>

int sum(int n) {
    if (n == 1) return 1;
    else return (n + sum(n-1));
}

int sum_iter(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += i;
    }
    return ret;
}

int main() {
    printf("sum(5)       = %d\n", sum(5));
    printf("sum(10)      = %d\n", sum(10));
    printf("sum(20)      = %d\n", sum(20));
    printf("sum_iter(5)  = %d\n", sum_iter(5));
    printf("sum_iter(10) = %d\n", sum_iter(10));
    printf("sum_iter(20) = %d\n", sum_iter(20));
}