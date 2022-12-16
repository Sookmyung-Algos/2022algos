#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define INF 2100000000 // 21억

int n, m, a, b, c;
long long dist[501];
bool cycle;
vector<pair<int, int>> v[501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF; // 모든 노드를 INF로 세팅

	dist[1] = 0; // 시작점 0으로 초기화

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int next = v[j][k].first;
				int d = v[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == n) // 사이클이 있는 경우
						cycle = true;
				}
			}
		}

	if (cycle)
		cout << -1 << '\n';

	else {
		for (int i = 2; i <= n; i++)
			cout << (dist[i] != INF ? dist[i] : -1) << '\n';
	}
}


// 출처: https://cocoon1787.tistory.com/438
