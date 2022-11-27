#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m, k, x;
int d[300001];
vector<int> r[300001];

void dijkstra(int s) {
  queue<int> q;
	d[s] = 0;
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
	bool visited = false;
  
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			visited = true;
			cout << i << endl;
		}
	}
  
	if (!visited)
		cout << "-1";
}

//참고 출처: https://velog.io/@khc41/%EB%B0%B1%EC%A4%80-18352-%ED%8A%B9%EC%A0%95-%EA%B1%B0%EB%A6%AC%EC%9D%98-%EB%8F%84%EC%8B%9C-%EC%B0%BE%EA%B8%B0-C
