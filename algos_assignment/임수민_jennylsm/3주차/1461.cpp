#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[10001] = { 0, };
int pindex = 0;
int result = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			pindex++;
	}

	sort(arr, arr + n);
	
	for (int i = n - 1; i >= pindex; i -= m) {
			result += (arr[i]*2);
	}

	for (int i = 0; i < pindex; i += m) {
			result += abs(arr[i] * 2);
	}

	result -= max(abs(arr[0]), abs(arr[n - 1]));

	cout << result << endl;
	return 0;
}
