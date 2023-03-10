#include <stdio.h>

int get_sum(int n) {
	if (n <= 1)
		return 1;
	return n + get_sum(n - 1);
}

int main() {
    printf("get_sum(5) = %d\n", get_sum(5));
    printf("get_sum(10) = %d\n", get_sum(10));
    printf("get_sum(20) = %d\n", get_sum(20));
}