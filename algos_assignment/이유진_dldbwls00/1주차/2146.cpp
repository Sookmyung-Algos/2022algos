#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
const int MAX = 100;

typedef struct{
	int y, x;
}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int n;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int y, int x, int cnt){
	visited[y][x] = true;
	graph[y][x] = cnt; //섬 번호

	for (int i = 0; i < 4; i++){
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
			if (graph[nextY][nextX] && !visited[nextY][nextX]) dfs(nextY, nextX, cnt);
		}
	}
}
int bfs(int cnt){
	queue<pair<int, int>> q; //섬의 좌표

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == cnt) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	int result = 0;

	while (!q.empty()){
		int curSize = q.size(); //한 칸 전진

		for (int i = 0; i < curSize; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {//범위 내에 있고
					if (graph[nextY][nextX] && graph[nextY][nextX] != cnt) return result; //다른 섬에 도착할 경우
					else if (!graph[nextY][nextX] && !visited[nextY][nextX]) {//아직 방문하지 않은 바다칸인 경우
						visited[nextY][nextX] = true; //방문 표시
						q.push(make_pair(nextY, nextX));
					}
				}
			}
		}
		result++;
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] && !visited[i][j]) dfs(i, j, cnt++); //dfs로 섬 표시
		}
	}

	int result = INF;
	for (int i = 1; i < cnt; i++) { //각 섬에서 제일 가까운 섬까지 다리를 놓을 경우 최소 길이
		memset(visited, false, sizeof(visited)); //함수 메모리 초기화 =
		result = min(result, bfs(i));
	}

	cout << result << endl;
	return 0;
}
