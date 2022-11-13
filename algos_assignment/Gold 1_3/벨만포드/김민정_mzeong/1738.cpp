#include <bits/stdc++.h>
using namespace std;
#define n_ 101

struct Edge {
    int u, v, w;
    Edge(int a, int b, int c) {
        u = a; v = b; w = c;
    }
};
vector<Edge> Ed;
vector<int> rev[n_];
int dist[n_], pre[n_];
queue<int> q; bool visited[n_];
int n, m, u, v, w, INF = 987654321;
bool cycle;

void find_route(int n) {
	if (n == 1) {
		cout << n << " ";
		return;
	}
	find_route(pre[n]);
	cout << n << " ";
}

void bellmanford() {
    dist[1] = 0; pre[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Ed.size(); j++) {
            auto [u, v, w] = Ed[j];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                if (i == n && visited[u]) cycle = true;
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		Ed.push_back(Edge(u, v, -w));
		rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) dist[i] = INF;
	
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int cidx = q.front(); q.pop();
		for (int nxt : rev[cidx]) {
		    if (!visited[nxt]) {
		        visited[nxt] = true;
		        q.push(nxt);
		    }
		}
	}
	bellmanford();
	if (cycle) {
		cout << -1 << "\n";
		return 0;
	}
	find_route(n);
	return 0;
}
