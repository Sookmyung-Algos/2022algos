#include <iostream>
using namespace std;

int main() {
	int N, K, A[11] = { 0, }, sum = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		sum += K / A[i];
		K = K % A[i];
	}

	cout << sum;

	return 0;
}
