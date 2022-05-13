#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, p, d;
	vector<pair<int, int>> arr;
	priority_queue<int> q;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		arr.push_back(make_pair(d, p));
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		q.push(-arr[i].second);
		ans += arr[i].second;

		if (q.size() > arr[i].first) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;

	return 0;
}
