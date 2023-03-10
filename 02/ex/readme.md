
## 10번 문제

### 정답
```
1
2
3
4
5
```

### 풀이
`recursive(int n)`은 출력보다 재귀호출을 먼저 실행한다. 그러므로 이 함수는 n이 1이 될 때까지 전부 순환한 후, 각 순환은 늦게 호출된 순(FILO)으로 n을 출력한 후 종료된다. 따라서 1 -> 5의 순서로 출력된다.

## 11번 문제

### 정답
```
****
```

### 풀이

```
asterisk(5) => asterisk(2) => asterisk(1) => "*"
                           => asterisk(1) => "*"
            => asterisk(2) => asterisk(1) => "*"
                           => asterisk(1) => "*"
```

## 13번 문제

### 정답

```c
int get_sum(int n) {
	if (n <= 1)
		return 1;
	return n + get_sum(n - 1);
}
```

## 14번 문제

### 정답

```c
double get_sum_inv(int n) {
	if (n <= 1)
		return 1;
	return 1.0 / n + get_sum_inv(n - 1);
}
```

## 16번 문제

### 정답

```c
int sum_iter(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += i;
    }
    return ret;
}
```

## 17번 문제

### 정답

```c
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
```
