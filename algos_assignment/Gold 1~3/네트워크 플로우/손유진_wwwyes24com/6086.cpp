#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 10000000;
int total = 0;
int flow = INF;
int source = 0, sink = 'Z'-'A';
int c[60][60];
int f[60][60];
int route[60];
vector<int> adj[60];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ac, bc;
		int a, b, ff;

		cin >> ac >> bc >> ff;

		if ('A' <= ac && ac <= 'Z')
			a = ac - 'A';
		else
			a = ac - 'a' + 26;
		if ('A' <= bc && bc <= 'Z')
			b = bc - 'A';
		else
			b = bc - 'a' + 26;

		c[a][b] += ff;
		c[b][a] += ff;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// 경로 있으면 계속 탐색 - bfs 이용
	while (true) {
		queue<int> q;
		q.push(source);
		fill(route, route + 60, -1);
		while (!q.empty() && route[sink] == -1) {
			int tmp = q.front();
			q.pop();
			for (int next : adj[tmp]) {
				if (c[tmp][next] > f[tmp][next] && route[next] == -1) {
					q.push(next);
					route[next] = tmp;
					if (next == sink)
						break;
				}
			}
		}
		if (route[sink] == -1)
			break;

		for (int i = sink; i != source; i = route[i]) {
			flow = min(flow, c[route[i]][i] - f[route[i]][i]);
		}
		for (int i = sink; i != source; i = route[i]) {
			f[route[i]][i] += flow;
			f[i][route[i]] -= flow;
		}
		total += flow;
	}
	cout << total;
}
