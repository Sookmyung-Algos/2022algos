#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M,S,E, u,v, p, c;
vector<pair<int, int>> edge[101];
int city[101];
long long dist[101];

int bfs(int S, int E) {
	if (S == E) return 1;
	int visited[101] = { 0 };
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].second;
			if (visited[next]) continue;
			visited[next] = 1;
			if (next == E) return 1;
			q.push(next);
			
		}
	}
	return 0;
}

int bellman(int S, int isCycle) {
	dist[S] = city[S];
	for (int j = 0; j < N-1 + isCycle; j++) {
		for (int k = 0; k < N; k++) {

			if (dist[k] == -INF) continue;
			for (int i = 0; i < edge[k].size(); i++) {
				int next_node = edge[k][i].second;
				int next_cost = edge[k][i].first;
				if (dist[next_node] >= dist[k] + next_cost + city[next_node]) continue;
				dist[next_node] = dist[k] + next_cost + city[next_node];
				if (j == N - 1) {
					if (bfs(next_node, E)) return next_node;
				}
			}
		}
	}
	return -1;
}


int main() {
    cin >> N >> S >> E >> M;
	edge->clear();
	for (int i = 0; i < M; i++) {
        cin >> u >> v >> p;
		edge[u].push_back({ -p,v });
	}
	for (int i = 0; i < N; i++) {
        cin >> city[i];
	}

	fill_n(dist, sizeof(dist) / sizeof(long long), -INF);
	
	int isInf = bellman(S, 1);
	if (dist[E] == -INF) {
        cout<<"gg\n";
	}
	else if (isInf!=-1) {
        cout <<"Gee\n";
	}
	else {
        cout << dist[E] <<"\n";
	}

	return 0;
}
