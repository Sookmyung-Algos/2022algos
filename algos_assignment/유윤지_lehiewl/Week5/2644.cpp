#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, m, ans;
vector<int> v[101];
int visit[101];


void dfs(int now, int end, int num) {
	visit[now] = 1;
	if (now == end) {
		ans = num;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visit[next]) {
			dfs(next, end, num + 1);
		}
	}
}

int main() {
	int x, y;
	cin >> n >> x >> y >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(x, y, 0);
	if (ans != 0) {
		cout << ans;
	}
	else cout << "-1";
}
