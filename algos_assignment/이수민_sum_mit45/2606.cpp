#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101]; // 인접 리스트
bool check[101];
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (!check[nx]) { // 방문한적 없다면
			dfs(nx);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >>a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << cnt << "\n";
	return 0;
}
