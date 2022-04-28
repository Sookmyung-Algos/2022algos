#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
int visited[101][101]; // 모두 100001로 초기화(최소값으로 갱신), bfs
queue <pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int mmin = 100001;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			int x = c - '0';
			arr[i][j] = x;
			visited[i][j] = 100001;
		}
	}

	//bfs
	q.push(make_pair(0,0)); // y,x,times
	visited[0][0] = 1;
	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (arr[ny][nx] == 1) { // 갈 수 있는 길이라면
					if (visited[ny][nx] == 100001) { // 처음가는 길이라면
						visited[ny][nx] = visited[cury][curx] + 1;
						q.push(make_pair(ny, nx));
						continue;
					}
					if(visited[ny][nx] > visited[cury][curx] + 1){
						visited[ny][nx] = visited[cury][curx] + 1;
						q.push(make_pair(ny, nx));
						continue;
					}
					
				}
			}
		}
	}

	cout << visited[N - 1][M - 1];

	return 0;
}
