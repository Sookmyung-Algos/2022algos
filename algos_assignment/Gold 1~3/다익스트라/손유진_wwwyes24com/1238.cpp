#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m, x;
int res1, res2, res;
vector<pair<int, int>> adj[1001];
int dist[10001];
bool visited[10000] = { 0 };

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int dist_v, v;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		do {
			dist_v = pq.top().first;
			v = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[v]);
		
		if (visited[v]) break;

		visited[v] = true;

		for (auto i : adj[v]) {
			int next = i.first;
			int next_v = i.second;
			if (dist_v + next_v < dist[next]) {
				dist[next] = dist_v + next_v;
				pq.push({ dist[next], next });
			}
		}
	}
	return dist[end];
}

int main() {
	

	scanf("%d %d %d", &n, &m, &x); // n개마을, 도착점 x, 간선개수 m
	for (int i = 0; i < m; i++) { 
		int start, end, t;
		scanf("%d %d %d", &start, &end, &t);
		adj[start].push_back(pair<int, int>(end, t));
	}
	
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 10000, 0);
		fill(dist, dist + 10000, 1000000000);
		res1 = dijkstra(i,x);
		fill(visited, visited + 10000, 0);
		fill(dist, dist + 10000, 1000000000);
		res2 = dijkstra(x, i);
		res = max(res, res1 + res2);
	}
	printf("%d", res);
}
