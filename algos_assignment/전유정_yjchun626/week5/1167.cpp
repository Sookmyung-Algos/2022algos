#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V, u ,v, c;
int node, ans;
bool visit[100001];
vector<pair<int, int>> graph[100001];

void dfs(int v) 
{
    cout << v << ' ' ;
    visit[v] = 1;
    for(int i=1; i<=N; i++) 
    {
        if(visit[i] == 1 || adj[v][i] == 0)
            continue;
        dfs(i); 
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); // 실행 빠르게

	cin >> V;

	for (int i = 1; i <= V; i++)
	{
		cin >> u;
		while (true)
		{
			cin >> v;
			if (v == -1) break;
			cin >> c;
			graph[u].push_back({ v,c });
		}
	}

	dfs(1, 0);
	ans = 0;
	for (int i = 1; i <= V; i++)
		visit[i] = false;
	dfs(node, 0);
	cout << ans << '\n';
}
