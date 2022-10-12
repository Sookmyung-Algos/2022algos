// 7576
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int N, M;
int arr[1001][1001];
queue<tuple<int, int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x; cin >> x;
			arr[i][j] = x;

			if (x == 1) {
				q.push(make_tuple(i, j, 0));
					arr[i][j] = -2; // starting point
			}
		}
	}

	int day = 0;
	while (!q.empty()) {

		int cury = get<0>(q.front());
		int curx = get<1>(q.front());
		int curday = get<2>(q.front());
		q.pop();

		int nday = curday + 1;
		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (arr[ny][nx] == -1) continue;
				if (arr[ny][nx] == 0) { // 갈 수 있는 길이라면
					arr[ny][nx] = nday;
					q.push(make_tuple(ny, nx, nday));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// cout << arr[i][j];
			if (arr[i][j] == -1 || arr[i][j] == -2) continue;
			else if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else if (arr[i][j] > ans) ans = arr[i][j];
		}
		//cout << "\n";
	}
	cout << ans;
	return 0;
}
