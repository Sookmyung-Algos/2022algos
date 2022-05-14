#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, k;
vector<int> v;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int start = 0;
	int end = v[N - 1];

	while (start <= end) {
		long long sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (v[i] > mid)
				sum += v[i] - mid;
		}
		if (sum < M)
			end = mid - 1;
		else {
			ans = mid;
			start = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
