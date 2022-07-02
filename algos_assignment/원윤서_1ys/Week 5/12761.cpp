#include <iostream>
#include <queue>
#include <algorithm>
const int MAX = 100001;

using namespace std;

int A, B, N, M;

bool visited[MAX];

int BFS(int idx) {
	queue<pair<int, int>> q;
	visited[idx] = true;
	q.push({ idx, 0 });
	
	while (!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (pos == M)
			return cnt;

		if (pos + 1 < MAX && !visited[pos + 1]) {
			visited[pos + 1] = true;
			q.push({ pos + 1, cnt + 1 });
		}

		if (pos - 1 >= 0 && !visited[pos - 1]) {
			visited[pos - 1] = true;
			q.push({ pos - 1, cnt + 1 });
		}

		if (pos + A < MAX && !visited[pos + A]) {
			visited[pos + A] = true;
			q.push({ pos + A, cnt + 1 });
		}

		if (pos - A >= 0 && !visited[pos - A]) {
			visited[pos - A] = true;
			q.push({ pos - A, cnt + 1 });
		}

		if (pos + B < MAX && !visited[pos + B]) {
			visited[pos + B] = true;
			q.push({ pos + B, cnt + 1 });
		}

		if (pos - B >= 0 && !visited[pos - B]){
			visited[pos - B] = true;
			q.push({pos - B, cnt + 1 });
		}

		if (pos * A < MAX && !visited[pos * A]){
			visited[pos * A] = true;
			q.push({pos * A, cnt + 1 });
		}

		if (pos * B < MAX && !visited[cur * B]){
			visited[cur * B] = true;
			q.push({cur * B, cnt + 1 });
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> N >> M;
	cout << BFS(N) << "\n";

	return 0;
}

//참고: https://jaimemin.tistory.com/947
