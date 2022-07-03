#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;
int a, b, n, m;
bool visited[MAX];
int cnt = 0;
int pos = 0;


int BFS(int idx) {
	queue< pair<int, int>>	q; // BFS에 쓰일 queue // {cnt, pos}
	visited[idx] = true;
	q.push({ 0, idx }); // 초기값 cnt = 0, pos = n

	while (!q.empty()) {
		cnt = q.front().first;
		pos = q.front().second;
		q.pop();

		if (pos == m) return cnt;

		if (pos + 1 < MAX && !visited[pos + 1]) {
			visited[pos + 1] = true;
			q.push({ cnt + 1, pos + 1 });
		} // 1칸전진
		
		if (pos - 1 > 0 && !visited[pos - 1]) {
			visited[pos - 1] = true;
			q.push({ cnt + 1, pos - 1 });
		} // 1칸후진

		if (pos + a < MAX && !visited[pos + a]) {
			visited[pos + a] = true;
			q.push({ cnt + 1, pos + a });
		} // a칸전진
    
		if (pos - a > 0 && !visited[pos - a]) {
			visited[pos - a] = true;
			q.push({ cnt + 1, pos - a });
		} // a칸후진

		if (pos + b < MAX && !visited[pos + b]) {
			visited[pos + b] = true;
			q.push({ cnt + 1, pos + b });
		} // b칸전진
		
		if (pos - b > 0 && !visited[pos - b]) {
			visited[pos - b] = true;
			q.push({ cnt + 1, pos - b });
		} // b칸후진

		if (pos * a < MAX && !visited[pos * a]) {
			visited[pos * a] = true;
			q.push({ cnt + 1, pos * a });
		} // a배점프

		if (pos * b < MAX && !visited[pos * b]) {
			visited[pos * b] = true;
			q.push({ cnt + 1, pos * b });
		} // b배점프
	}
	return -1;
}


int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> n >> m;
	cout << BFS(n);
}
