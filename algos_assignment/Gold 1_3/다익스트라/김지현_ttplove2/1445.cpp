#include <iostream>
#include<string.h>
#include <algorithm>
#include <queue>
#include<cstdio>
#include <vector>
#define MAX 51
#define INF 50
using namespace std;

int N, M;
char map[MAX][MAX];
pair<int,int> d[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
pair<int, int> from;
pair<int, int> to;
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

void dijkstra() {
	int tempX, tempY, trash, step;
	pq.push({ { -1, 0 }, { from.first, from.second } });
	d[from.first][from.second] = { 1, 0 };

	while (!pq.empty()) {
		tempX = pq.top().second.first;
		tempY = pq.top().second.second;
		trash = -pq.top().first.first; // 쓰레기 최소 개수
		step = -pq.top().first.second; // 쓰레기 옆을 지나가는 칸의 개수
		pq.pop();

		if (d[tempX][tempY] < make_pair(trash, step)) continue;
		for (int i = 0; i < 4; i++) {
			int nx = tempX + dx[i];
			int ny = tempY + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 'g') {
				pair<int, int> tmp = { trash + 1, step };
				if (d[nx][ny] == make_pair(0, 0) || tmp < d[nx][ny]) {
					d[nx][ny] = tmp;
					pq.push({ {-tmp.first, -tmp.second}, {nx, ny} });
				}
			} else if (map[nx][ny] == 'h') {
				pair<int, int> tmp = { trash, step + 1 };
				if (d[nx][ny] == make_pair(0, 0) || tmp < d[nx][ny]) {
					d[nx][ny] = tmp;
					pq.push({ {-tmp.first, -tmp.second}, {nx, ny} });
				}
			} else {
				pair<int, int> tmp = { trash, step };
				if (d[nx][ny] == make_pair(0, 0) || tmp < d[nx][ny]) {
					d[nx][ny] = tmp;
					pq.push({ {-tmp.first, -tmp.second}, {nx, ny} });
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { // j가 행, i가 열
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				from = { i, j };
			} else if (map[i][j] == 'F') {
				to = { i, j };
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { // j가 행, i가 열
			if (map[i][j] == 'g') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (map[nx][ny] != 'g') map[nx][ny] = 'h';
					}
				}
			}
		}
	}
	map[to.first][to.second] = '.';
	dijkstra();
	cout << d[to.first][to.second].first - 1 << ' ' << d[to.first][to.second].second;
	return 0;
}
