#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
	fastio;
	int n; cin >> n;
	vector<int> v(n), w(n), idx(n + 1), t(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> w[i], idx[w[i]] = i;
	for (int i = 0; i < n; i++) t[i] = idx[v[i]];
	vector<int> LIS, info(n);
	for (int i = 0; i < n; i++) {
		if (LIS.empty() || LIS.back() < t[i]) LIS.push_back(t[i]), info[i] = LIS.size();
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), t[i]);
			*it = t[i];
			info[i] = it - LIS.begin() + 1;
		}
	}
	cout << LIS.size() << '\n';
	vector<int> path;
	for (int i = n, temp = LIS.size(); i --> 0;) {
		if (info[i] == temp) {
			path.push_back(t[i]);
			temp--;
		}
	}
	reverse(path.begin(), path.end());
	for (auto i : path) cout << w[i] << ' '; cout << '\n';
}
