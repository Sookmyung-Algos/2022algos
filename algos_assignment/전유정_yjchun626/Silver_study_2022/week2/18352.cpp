#include <vector>
#include <iostream>
#include <list>

using namespace std;

//도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
int N, M, K, X;

// 각 벡터들 생성
vector<vector<int> > graph; // 도시 정보
vector<int> dist; // 거리 정보
vector<int> result; // 거리가 K인 도시

// bfs 너비 우선 탐색 함수
void bfs() {
	int start = X; // X번 도시로부터 시작
	dist[X] = 0;

	list<int> queue; 
	queue.push_back(X);

	// bfs
	while (!queue.empty()) {
		int now = queue.front(); 
		queue.pop_front();

		// 현재 도시를 기준으로 연결된 도시를 탐색
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i]; // 다음 도시 번호
			if (dist[next] == -1) { // 도시를 이미 탐색하지 않았다면
				dist[next] = dist[now] + 1; // 현재 도시의 거리 + 1로 거리를 기록
				queue.push_back(next); // 다음 도시 삽입 후 재탐색
			}
		}

	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) // 거리가 K인 도시 번호를 오름차순으로 result 벡터에 삽입
			result.push_back(i);
	}
}

int main() {
	cin >> N >> M >> K >> X;
	graph = vector<vector<int> >(N + 1); // 그래프 생성
	dist = vector<int>(N + 1, -1); // 거리벡터 생성

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	bfs(); // bfs 탐색
	if (result.size() == 0) cout << -1;
	else {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}
}
