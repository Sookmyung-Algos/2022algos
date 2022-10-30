#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
const long long INF = 1e18;
typedef pair<int, int> P;

int main() {
	int n, a, b, m;
	long long dist[200];
	vector<P> adj[200];
	bool visited[200];
	int money[200];
	queue<int> q;

	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start].push_back(P(end, cost));
	}

	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	fill(dist, dist + n, INF);
	fill(visited, visited + n, false);
	dist[a] = -money[a];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto& p : adj[j]) {
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d - money[next]) {
					dist[next] = dist[j] + d - money[next];
					if (i == n - 1) {
						visited[j] = true;
						q.push(j);
					}

				}
			}
		}
	}
	
	if (dist[b] == INF) {
		cout << "gg";
	}
	else {
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			for (auto i : adj[tmp]) {
				int next = i.first;
				if (visited[next])
					continue;
				q.push(next);
				visited[next] = true;
			}
		}
		if (visited[b] == true) {
			cout << "Gee";
		}
		else {
			cout << -dist[b];
		}
	}
}
