#include <iostream>
#include <vector>

using namespace std;
vector<int> v[2000];
bool visit[2000];
bool avail = false;

void dfs(int idx, int count) {
	if (count == 4) {
		avail = true;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next, count + 1);
			visit[next] = false;
		}
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visit[j] = false;
		visit[i] = true;
		dfs(i, 0);
		if (avail) break;
	}
	if (avail) cout << 1;
	else cout << 0;
	return 0;
}
