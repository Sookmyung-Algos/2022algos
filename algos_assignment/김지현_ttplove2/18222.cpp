#include <iostream>
using namespace std;

long long arr[64];
long long K;

long long solve(long long k) {
	if (k == 1) return 0;
	for (int i = 1; i < 64; i++) {
		if (arr[i] >= k) return 1 - solve(k - arr[i - 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> K;
	arr[0] = 1;
	for (int i = 1; i < 64; i++)
		arr[i] = arr[i - 1] * 2;
	cout << solve(K);

	return 0;
}
