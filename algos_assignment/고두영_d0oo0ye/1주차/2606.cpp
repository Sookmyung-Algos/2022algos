#include <iostream>
#include <vector>
using namespace std;

vector<int> a[101];
bool visit[101];
int n, m, u, v;
int ans = 0;

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!visit[y]) {
			dfs(y);
			ans++;
		}
	}
}

int main() {
	cin >> n; 
	cin >> m; 
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		// 정점끼리 연결해주기
	}
	dfs(1);
	cout << ans << endl;
}
