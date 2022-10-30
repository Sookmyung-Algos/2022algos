#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 2501
using namespace std;

int T, N, M, W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		vector<pair<pair<int, int>, int>> road(N + 1); // 도로 정보
		vector<int> d(N + 1, INF); // 최소 비용
		d[1] = 0;

		for (int i = 0; i < M; i++) { // 도로 정보
			int s, e, t;
			cin >> s >> e >> t;
			road.push_back({ {s, e}, t });
			road.push_back({ {e, s}, t });
		}
		for (int i = 0; i < W; i++) { // 웜홀 정보
			int s, e, t;
			cin >> s >> e >> t;
			road.push_back({ {s, e}, -t });
		}
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			for (int k = 0; k < road.size(); k++) {
				int temp = road[k].first.first;
				int next = road[k].first.second;
				int time = road[k].second;
				if (d[temp] + time < d[next]) {
					d[next] = d[temp] + time;
					if (i == N) flag = true;
				}
			}
		}
		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}
