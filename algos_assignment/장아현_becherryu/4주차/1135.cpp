#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> v;

int dfs(int cur) {
	vector<int> vec;
	int i = 0;
	int w = v[cur].size() - 1;

	for (int nx : v[cur])
		vec.push_back(dfs(nx));

	sort(vec.begin(), vec.end());

	for (int j = 0; j < vec.size(); ++j)
		i = max(i, vec[j] + w--);

	return i + 1;
}

int main() {
	cin >> n;
	v.resize(n);

	for (int j = 0; j < n; ++j) {
		int p;
		cin >> p;

		if (p == -1)
			continue;
		v[p].push_back(j);
	}
	int ans = dfs(0);

	cout << ans - 1;

	return 0;
}
