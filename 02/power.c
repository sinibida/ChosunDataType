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

int main() {
    printf("2^10 = %lf\n", power(2.0, 10));
    printf("5^5 = %lf\n", power(5.0, 5));
    printf("10^5 = %lf\n", power(10.0, 5));
    printf("1.01^256 = %lf\n", power(1.01, 256));

    return 0;
}
