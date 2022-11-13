#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 101
using namespace std;

int N, M;
vector<pair<pair<int, int>, int>> road;
vector<int> rev[MAX];
bool visit[MAX]; // 방문 체크
int d[20001]; // 최단 비용 저장
int route[MAX]; // 경로 저장

void dijkstra() {
	queue<int> q;
	q.push(N);
	visit[N] = true;

	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 0; i < rev[from].size(); i++) {
			int to = rev[from][i];
			if (!visit[to]) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
}

bool bf() {
	bool flag = false; // 최적의 경로가 존재하는 지 판별하기 위한 변수
	for (int i = 1; i <= N; i++) d[i] = INF;
	d[1] = 0;
	route[1] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < road.size(); j++) {
			int from = road[j].first.first;
			int to = road[j].first.second;
			int cost = road[j].second;
			if (d[from] != INF && d[to] > d[from] + cost) {
				if (i == N && visit[from]) flag = true;
				d[to] = d[from] + cost;
				route[to] = from; // 경로 거꾸로 저장
			}
		}
	}
	return flag;
}

void result(int x) {
	if (x == 0) return;
	result(route[x]);
	cout << x << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		road.push_back({{ u, v }, -w});
		rev[v].push_back(u);
	}
	dijkstra();

	if (bf()) {
		cout << "-1" << "\n";
		return 0;
	}
	result(N);
	return 0;
}
