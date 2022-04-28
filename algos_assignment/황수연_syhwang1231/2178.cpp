#define _CRT_SECURE_NO_WARNINGS
#define MAX 101
#include <iostream>
#include <queue>

using namespace std;

int n, m;  // n: 세로(행), m: 가로(열)
int cnt[MAX][MAX];  // 해당 위치로 올 때까지 (1,1)에서부터 지나온 칸 수
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = { 1, -1, 0, 0 };  // row direction
int dc[4] = { 0, 0, 1, -1 };  // column direction

void bfs(void) {
    queue <pair<int, int>> q;  // 좌표 다루기 위한 queue
    
	q.push(make_pair(1, 1));
	cnt[1][1] = 1;  // 시작 위치도 개수 셈
	int r,c;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		if (r == n && c == m)  // 도착 위치의 좌표인 경우
			return;
			
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];  // x,y 좌표 이동
			int nc = c + dc[i];

			if (nr <= 0 || nr > n || nc <= 0 || nc > m)  // map 밖으로 나가면 continue
				continue;
				
			if (maze[nr][nc] == 1 && !visited[nr][nc]) {  // 이동할 수 있고 방문하지 않았다면
				visited[nr][nc] = true; // 방문 표시
				q.push(make_pair(nr, nc));  // 인접한 좌표를 q에 push
				cnt[nr][nc] = cnt[r][c] + 1;  // 칸 수 1 증가
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	bfs();
	cout << cnt[n][m];
	return 0;
}
