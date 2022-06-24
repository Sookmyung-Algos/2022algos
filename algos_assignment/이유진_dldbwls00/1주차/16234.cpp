#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 50;

typedef struct {
	int y, x;
}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pair<int, int>> v;
int n, l, r;
int ppl, num;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int y, int x){
	for (int i = 0; i < 4; i++){
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		int diff = abs(graph[y][x] - graph[nextY][nextX]);

		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
			if (l <= diff && diff <= r && !visited[nextY][nextX]) { //조건 충족
				visited[nextY][nextX] = true;
				v.push_back({ nextY, nextX });
				ppl += graph[nextY][nextX];
				num++;
				dfs(nextY, nextX);
			}
		}
	}
}

int main(void) {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	}

	int result = 0;

	while (1) {
		memset(visited, false, sizeof(visited)); //함수메모리 초기화
		bool found = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				visited[i][j] = true;
				ppl = graph[i][j];
				num = 1;
				v.clear();
				v.push_back({ i, j });
				dfs(i, j);

				if (num >= 2) { //국경이 하나라도 열리는 경우
					found = true;

					for (int i = 0; i < v.size(); i++) {//업데이트
						graph[v[i].first][v[i].second] = ppl / num;
					}
				}
			}
			
		}
		if (found) result++;
		else break;
	}
	cout << result << "\n";
	return 0;
}
