#include <iostream>
using namespace std;
int N, K, ans;
int n[1000001];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		n[b] = a;
	}
	K = 2 * K + 1;
	int sum = 0;
	for (int i = 0; i <= 1000001; i++) {
		if (i >= K) {
			sum -= n[i - K];
		}
		sum += n[i];
		ans = max(sum, ans);
	}
	cout << ans;
	return 0;
}
