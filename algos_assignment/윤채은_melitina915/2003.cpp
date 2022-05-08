#include <iostream>
using namespace std;

int n, m;
int arr[10001];
int add[10001];

int main() {
	int cnt = 0, i, j;

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		add[i] = add[i - 1] + arr[i];
	}

	for (i = n; i >= 1; i--) {
		for (j = 1; j <= i; j++) {
			if (add[i] - add[j - 1] == m) {
				cnt++;
			}
		}
	}

	cout << cnt;
}
