#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 51
using namespace std;

int N, M, START, END;
vector<pair<pair<int, int>, int>> ride;
vector<int> rev[MAX];
vector<int> route;
bool visit[MAX] = { false, };
int p[MAX];
int earn[MAX];
int INF = -int(1e9);

bool dijkstra(int s) {
	queue<int> q;
	q.push(s);
	visit[s] = true;

	while (!q.empty()) {
		int next = q.front();
		q.pop();
		if (next == END) return true; // 싸이클 발생
		for (int i = 0; i < ride.size(); i++) {
			int from = ride[i].first.first;
			int to = ride[i].first.second;
			int cost = ride[i].second;
			if (from == next && !visit[to]) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
	return false;
}

void bf() {
	long long d[51];
	for (int i = 0; i < N; i++) d[i] = INF;
	d[START] = earn[START];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ride.size(); j++) {
			int from = ride[j].first.first;
			int to = ride[j].first.second;
			int cost = ride[j].second;
			if (d[from] != INF && d[to] < d[from] + cost) {
				d[to] = d[from] + cost;
			}
		}
	}
	if (d[END] == INF) { // 도착 도시에 도착하는 것이 불가능
		cout << "gg";
		return;
	}
	for (int i = 0; i < ride.size(); i++) {
		int from = ride[i].first.first;
		int to = ride[i].first.second;
		int cost = ride[i].second;
		if (d[from] != INF && d[to] < d[from] + cost) {
			if (dijkstra(to)) {
				cout << "Gee";
				return;
			}
		}
	}
	cout << d[END];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> START >> END >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ride.push_back({ { u, v }, -w });
	}
	for (int i = 0; i < N; i++) {
		cin >> earn[i];
	}
	for (int i = 0; i < M; i++) {
		ride[i].second += earn[ride[i].first.second]; // 교통 수단의 가격에 번 돈의 가격을 더함
	}
	bf();
	return 0;
}
