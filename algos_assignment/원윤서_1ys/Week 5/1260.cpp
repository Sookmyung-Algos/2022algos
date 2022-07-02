#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

int N, M, V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visited[v] = 1;
	cout << v << ' ';

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[v][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
				cout << i << ' ';
			}
		}
	}
}

int main(void) {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b] = 1;
	}

	visited[V] = 1;
	DFS(V);
	cout << endl;

	memset(visited, false, sizeof(visited));

	BFS(V);

	cout << endl;

	return 0;
}
