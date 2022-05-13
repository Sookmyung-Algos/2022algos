#include <iostream>
#include <algorithm>
using namespace std;

int N, M, target;
int a[100001];

void binary_search(int n, int arr[]) {
	int start = 0, end = N - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (n == arr[mid]) {
			cout << 1 << '\n';
			return;
		}

		else if (n <= arr[mid]) {
			end = mid - 1;
		}

		else if (n >= arr[mid]) {
			start = mid + 1;
		}
	}

	cout << 0 << '\n';
	return;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> target;
		binary_search(target, a);
	}

	return 0;
}
