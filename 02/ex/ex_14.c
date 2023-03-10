#include <stdio.h>

double get_sum_inv(int n) {
	if (n <= 1)
		return 1;
	return 1.0 / n + get_sum_inv(n - 1);
}

int main() {
    printf("get_sum_inv(5) = %lf\n", get_sum_inv(5));
    printf("get_sum_inv(10) = %lf\n", get_sum_inv(10));
    printf("get_sum_inv(20) = %lf\n", get_sum_inv(20));
}