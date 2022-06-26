#include <iostream>
using namespace std;
int N, K, B;
int a, sum, ans;
int n[100001];
int main() {
	cin >> N >> K >> B;
	for (int i = 0; i < B; i++) {
		cin >> a;
		n[a] = 1;
	}
	for (int i = 1; i <= K; i++) {
		if (n[i] == 1) {
			sum++;
		}
	}
	ans = sum;
	for (int i = K + 1; i <= N; i++) {
		if (n[i - K] == 1)sum--;
		if (n[i] == 1)sum++;
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
