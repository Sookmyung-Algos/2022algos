#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int V, u, v, c;
int node, ans;
bool visit[100001];
vector<pair<int, int>> graph[100001];

void dfs(int x, int dist){
	visit[x] = true;
	if (dist > ans){
		ans = dist;
		node = x;
	}

	for (int i = 0; i < graph[x].size(); i++){
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
		if (!visit[next_node]){
			visit[next_node] = true;
			dfs(next_node, next_dist);
			visit[next_node] = false;
		}
	}
}

int main()
{
	cin >> V;
	for (int i = 1; i <= V; i++){
		cin >> u;
		while (true)		{
			cin >> v;
			if (v == -1) break;
			cin >> c;
			graph[u].push_back({ v,c });
		}
	}

	dfs(1, 0);
	ans = 0;
	for (int i = 1; i <= V; i++) {
		visit[i] = false;
	}
	dfs(node, 0);
	cout << ans << '\n';
}
