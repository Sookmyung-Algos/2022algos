#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pi;
const long long INF = 1e18;
long long dist[101];
int pre[101];

int n, m;
vector<pi> adj[101];
vector<pi> rev_adj[101];

bool goal[101];

void check_goal() {
	queue<int> Q;

	Q.push(n);
	goal[n] = 1;

	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (auto &i : rev_adj[x]) {
			int nx = i.first;
			if (goal[nx] == 0) {
				Q.push(nx);
				goal[nx] = 1;
			}
		}
	}
}

void print(int n) {

	if (n == 0) return;
	print(pre[n]);
	cout << n << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,-w });
		rev_adj[v].push_back({ u,-w });
	}
	
	check_goal();

	//시작점에서 도착점 가는 길이 없는 경우
	if (goal[1] == 0) {
		cout << -1 << '\n';
		return 0;
	}

	fill(dist, dist + 101, INF);

	dist[1] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto& a : adj[j]) {
				int nx = a.first;
				int d = a.second;

				if (dist[j] != INF && dist[nx] > dist[j] + d) {
					pre[nx] = j;
					dist[nx] = dist[j] + d;

					if ((i == n-1) && (goal[j])) {
						cout << -1 << '\n';
						return 0;
					}
				}
			}
		}
	}
	print(n);


	return 0;
}
