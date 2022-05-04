#include <iostream>
#include <algorithm>
using namespace std;

int t[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	long long sum = 0, maxSum; // 수의 범위 조심할것!

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}

	for (int i = 1; i <= m; i++) {
		sum += t[i];
	}

	maxSum = sum;

	for (int i = 1; i <= n - m - 1;) {
		sum -= t[i++];
		sum += t[i + m - 1];
		maxSum = max(sum, maxSum);
	}

	cout << maxSum;

	return 0;
}
