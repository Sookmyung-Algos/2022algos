#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	int graph[401][401] = { 0, };

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c; //a->b = c
	}
	
	for (int k = 1; k <= v; k++) {//플로이드 와샬(사이클찾기)
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] != 0) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); //최소거리
					else graph[i][j] = graph[i][k] + graph[k][j];
				}
			}

		}
	}

	int answer = 10000000000;
	int check = 0;
	for (int i = 1; i <= v; i++) {
		if (graph[i][i] != 0) {
			answer = min(answer, graph[i][i]); //최소 도로의 길이
			check = 1;
		}
	}

	if (check == 0) cout << "-1\n"; //사이클이 없는 경우
	else cout << answer << "\n";
	return 0;
}
