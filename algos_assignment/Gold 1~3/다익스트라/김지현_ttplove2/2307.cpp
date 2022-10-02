#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 987654321
using namespace std;

int N, M;
int ans;
vector<pair<int, int>> road[MAX]; // 도로 정보 저장
vector<int> route; // 최단 경로 저장
pair<int, int> banned; // 막은 도로 정보 저장
bool flag = true; // 첫번째 다익스트라 함수 수행을 구분하기 위한 bool형 변수

int dijkstra() {
	priority_queue<pair<int, int>> pq;
	vector<int> d(N + 1, INF); // 최단 거리 테이블
	d[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int x = pq.top().second; // 현재 도시(노드)
		int time1 = pq.top().first; // 시간(거리)
		pq.pop();
		for (int i = 0; i < road[x].size(); i++) {
			int y = road[x][i].first; // 도착 도시(노드)
			int time2 = road[x][i].second - time1; // 비용(시간)
			if (banned.first == x && banned.second == y || banned.first == y && banned.second == x) { // 막힌 도로에 해당하면 넘어감
				continue;
			}
			if (time2 < d[y]) {
				if (flag) route[y] = x; // 처음 다익스트라 함수를 호출한 것이므로 
				d[y] = time2;
				pq.push(make_pair(-time2, y));
			}
		}
	}
	return d[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int prevTime = 0, newTime = 0; // 기존 탈출시간과, 도로를 막은 후의 탈출 시간을 비교하기 위한 변수
	cin >> N >> M;
	route.resize(N + 1, -1);
	banned.first = 0; banned.second = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back(make_pair(b, c));
		road[b].push_back(make_pair(a, c));
	}
	route[1] = 1;
	prevTime = dijkstra(); // 도로를 막기 전의 최단 시간 측정
	flag = false;

	for (int i = N; i != route[i]; i = route[i]) { // N부터 도로를 하나씩 지워서 최대 지연 시간을 측정
		banned.first = i; 
		banned.second = route[i];
		newTime = max(newTime, dijkstra());
		if (newTime == INF) break;
	}
	if (newTime == INF) cout << "-1"; // 도로를 막아서 도착하지 못한 경우
	else cout << newTime - prevTime;

	return 0;
}
