#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int arr[100001];
	int lis[100001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[0];
	int cnt = 0;

	for (int i = 1; i < n; i++) {
		if (lis[cnt] < arr[i]) {
			lis[cnt + 1] = arr[i];
			cnt++;
		}
		else {
			int idx = lower_bound(lis, lis + cnt, arr[i]) - lis;
			lis[idx] = arr[i];
		}
	}

	cout << n - (cnt + 1) << "\n";

	return 0;
}
