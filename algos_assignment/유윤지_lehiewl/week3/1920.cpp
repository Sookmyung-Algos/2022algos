#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int A[100001];

void binary_search(int n, int arr[]) {
	int start = 0;
	int end = N - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (n == arr[mid]) {
			cout << '1' << '\n';
			return;
		}
		else if (n < arr[mid]) {
			end = mid - 1;
		}
		else if (n > arr[mid]) {
			start = mid + 1;
		}
	}
	cout << '0' << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A[i] = num;
	}
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;
		binary_search(m, A);
	}
	return 0;
}
