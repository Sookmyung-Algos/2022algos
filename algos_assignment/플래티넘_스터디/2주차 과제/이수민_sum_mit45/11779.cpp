// G3_최소비용 구하기2

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 1000000000
using namespace std;

int V, E; // 도시(정점), 버스(간선)
vector<pair<int,int>> adj[1001]; // 인접 노드
int before[1001]; // 이전 노드
int Start, End;

void dijkstra(int start) {
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,start }); // (거리, 시작노드) 순으로
	int dist[1001];
	for (int i = 1; i <= V; i++) dist[i] = INF;
	dist[start] = 0; // 시작하는 정점 거리 = 0

	while (!pq.empty()) {
		int u = pq.top().second; // 시작 정점
		int d = -pq.top().first; // 거리
		pq.pop();

		if (d > dist[u]) continue;
		for (auto i : adj[u]) {
			int next = i.first; int ndist = d + i.second;
			if (dist[next] <= ndist) continue;
			dist[next] = ndist; 
			before[next] = u;
			pq.push({ -ndist,next });
		}
	}

	cout << dist[End] << "\n";
	int checkbe = before[End];
	stack <int> order;
	order.push(End);

	while (checkbe != Start) {
		order.push(checkbe);
		checkbe = before[checkbe];
	}
	order.push(Start);

	cout << order.size() << "\n";

	while (!order.empty()) {
		int tmp = order.top(); order.pop();
		cout << tmp << " ";
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// 입력
	cin >> V;
	cin >> E;

	for (int i = 0; i < E; i++) {
		int s, e, c; // start, end, cost
		cin >> s >> e >> c;
		adj[s].push_back(make_pair(e, c));
	}
	cin >> Start >> End;

	dijkstra(Start);

	return 0;
}
