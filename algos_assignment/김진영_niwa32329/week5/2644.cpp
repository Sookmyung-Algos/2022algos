#include <iostream>
#include <queue>

using namespace std; 

int visit[101]; 
queue<int> q; 
int graph[101][101]; 
int n, a, b, m; 


void bfs(int node) {
	q.push(node); 

	while (!q.empty()) {
		node = q.front();
		q.pop(); 

		for (int i = 1; i <= n; i++) {
			if (graph[node][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] =visit[node]+1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1; 
	}

	bfs(a);

	if (visit[b] == 0) visit[b] = -1; 

	cout << visit[b]; 

	return 0; 
}
