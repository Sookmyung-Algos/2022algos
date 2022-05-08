#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[23456] = { 0 };

int main() {
	int n, m, result = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int a = 0, b = n - 1;

	sort(arr, arr + n);

	while (a < b) {
		if (arr[a] + arr[b] == m) {
			result++;
			b--;
			a++;
		}
		if (arr[a] + arr[b] > m) {
			b--;
		}
		if (arr[a] + arr[b] < m) {
			a++;
		}
	}

	printf("%d", result);

	return 0;
}
