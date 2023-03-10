#include <stdio.h>

// 순환함수
int bicof(int n, int k) {
    if (0 < k && k < n) return bicof(n - 1, k - 1) + bicof(n - 1, k);
    else if (0 == k || k == n) return 1;
    else return 0;
}

// bicof(n, k)의 작동방식에 더 유사한 반복함수 (덧셈 사용)
//     - 코드가 복잡하고 느리지만 예상못한 오버플로우가 발생하지 않음

#define TEMP_SIZE 128

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int bicof_iter(int n, int k) {
    int temp[TEMP_SIZE] = {0, };
    temp[0] = 1;
    for (int i = 1; i <= n; i++) {
        temp[i] = 1;
        for (int j = MIN(k, i - 1); j >= MAX(1, k + i - n); j--) {
            temp[j] += temp[j - 1];
        }
    }
    return temp[k];
}

// 조합의 정의를 응용한 반복함수
//     - 코드가 간결하고 빠르지만 다소 큰 n, k에서 오버플로우 발생
int bicof_iter_2(int n, int k) {
    long ret = 1;
    for (int i = n - k + 1; i <= n; i++) {
        ret *= i;
    }
    for (int i = 1; i <= k; i++) {
        ret /= i;
    }
    return (int)ret;
}

int main() {
    printf("bicof(5, 3)       = %d\n", bicof(5, 3));
    printf("bicof(10, 7)      = %d\n", bicof(10, 7));
    printf("bicof(20, 12)      = %d\n", bicof(20, 12));
    printf("bicof_iter(5, 3)  = %d\n", bicof_iter(5, 3));
    printf("bicof_iter(10, 7) = %d\n", bicof_iter(10, 7));
    printf("bicof_iter(20, 12) = %d\n", bicof_iter(20, 12));
    printf("bicof_iter_2(5, 3)  = %d\n", bicof_iter_2(5, 3));
    printf("bicof_iter_2(10, 7) = %d\n", bicof_iter_2(10, 7));
    printf("bicof_iter_2(20, 12) = %d\n", bicof_iter_2(20, 12));
}