#include <iostream>
#include <queue>
#include <tuple>
#define INF 30000000
using namespace std;

// 0 이미 존재, 1 단위도로 없음, 2 단위도로 없음, -1 도로건설못함

int m, n; // m세로, n가로
int road[1001][1001];
int dist[1001][1001];
int v[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void check(int sm, int sn) {

	priority_queue <tuple<int, int, int>, vector<tuple<int,int,int>>, greater<>> pq; // 비용, m(세로), n(가로)
	pq.push(make_tuple(road[sm][sn], sm, sn));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	dist[sm][sn] = road[sm][sn]; 

	while (!pq.empty()) {
		tuple <int, int, int> tmp;
		tmp = pq.top(); pq.pop();
		int cost = get<0>(tmp);
		int x = get<2>(tmp);
		int y = get<1>(tmp);
        if (y == m && x == n)break;

		if (cost > dist[y][x]) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || ny <1 || nx > n || ny > m || road[ny][nx] == -1) continue;
			
			int nc = road[ny][nx] + cost;
			if (dist[ny][nx] > nc) {
				dist[ny][nx] = nc;
				pq.push(make_tuple(nc, ny, nx));
			}
		}

	}

	if (dist[m][n] == INF) {
		cout << -1;
	}
	else {
		cout << dist[m][n];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> road[i][j];
		}
	}

	if (road[1][1] == -1 || road[m][n] == -1) {
		cout << -1;
		return 0;
	}

	check(1, 1); // 시작
	return 0;
}
