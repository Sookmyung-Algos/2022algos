#include <stdio.h>

#define MAX_ARR 100000
#define max(x,y) x > y ? x : y

int main() {
	int n;
	int arr[MAX_ARR];
	int dp[MAX_ARR];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &arr[i]);
	}

	int r = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		r = max(dp[i], r);
	}

	printf("%d\n", r);

	return 0;
}
