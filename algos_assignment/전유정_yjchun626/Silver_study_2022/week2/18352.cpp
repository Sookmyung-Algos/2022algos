#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, k, x;
int d[300001];
vector<int> r[300001];

void dijkstra(int s) {
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < r[cur].size(); i++) {
			int next = r[cur][i];
			if (d[next] > d[cur] + 1) {
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		r[s].push_back(e);
	}
	dijkstra(x);
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			check = true;
			cout << i << endl;
		}
	}
	if (!check)
		cout << "-1";
}
