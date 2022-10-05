// G1_16118 달빛 여우

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define INF 2e9
using namespace std;

int V, E; // 정점(나무), 간선(오솔길)
vector <pair<int, int>> adj[4001];
int dist_f[4001];
int dist_w[4001][2];

void dijkstraf(int start) {
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, start)); // (거리, 시작노드) 순으로
	
	for (int i = 1; i <= V; i++) dist_f[i] = INF;
	dist_f[start] = 0; // 시작하는 정점 거리 = 0

	while (!pq.empty()) {
		int u = pq.top().second; // 시작 정점 
		int d = -pq.top().first; // 거리
		pq.pop();

		if (d > dist_f[u]) continue;

		for (auto i : adj[u]) {
			int next = i.first; 
			int ndist = d + 2 * i.second; // 여우 거리는 2배씩 더하기

			if (dist_f[next] <= ndist) continue; // 거리갱신 안됨

			dist_f[next] = ndist;
			pq.push(make_pair(-ndist, next));
		}
	}
}

typedef pair<pair<int, int>, int> ppi;

void dijkstraw(int start) {
	priority_queue <ppi> pq;
	pq.push({ { 0,1 },1 }); // (거리, 시작노드) 순으로

	for (int i = 1; i <= V; i++) {
		dist_w[i][0] = INF;
		dist_w[i][1] = INF;
	}
	dist_w[start][start] = 0; // 시작하는 정점 거리 = 0

	while (!pq.empty()) {
		int u = pq.top().first.second; // 시작 정점 
		int d = -pq.top().first.first; // 거리
		int speed = pq.top().second;
		pq.pop();

		if (d > dist_w[u][speed]) continue;

		for (auto i : adj[u]) {
			int next = i.first;
			int ndist;

			if (speed) ndist = d + i.second; // 1이라면(홀수번쨰)
			else ndist = d + i.second * 4;

			if (dist_w[next][speed^1] <= ndist) continue; // 거리갱신 안됨

			dist_w[next][speed^1] = ndist;
			pq.push({{ -ndist, next }, speed ^ 1});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}

	// 양 버전
	dijkstraf(1);

	// 늑대버전
	dijkstraw(1);

	// 배열비교하면서 값 적은 개수 => 양 개수
	int ans = 0;
	for (int i = 2; i <= V; i++) {
		int wolf = min(dist_w[i][0], dist_w[i][1]);

		//늑대 거리가 크면 여우가 먼저 도착
		if (dist_f[i] < wolf)
			ans++;
	}
	cout << ans;
	return 0;
}
