#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t;
struct Edge {
	Edge(){}
	Edge(int to_, int weight_) :to(to_), weight(weight_) {}
	int to;
	int weight;
};
vector<vector<Edge>> adj;
vector<bool> visited;

int dfs(int cur, int before)
{
	int ret = 0, beforeWeight = 0;

	for (Edge next : adj[cur])
	{
		if (next.to == before) {
			beforeWeight = next.weight;
			continue;
		}

		if (visited[next.to] == false) {
			visited[next.to] = true;
			ret += dfs(next.to, cur);
		}
	}

	if (adj[cur].size() == 1)
		return beforeWeight;


	if (ret == 0)
		return 0;
	else
		return min(ret, beforeWeight);
}
int main()
{
	scanf("%d", &t);

	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		adj = vector<vector<Edge>>();
		adj.resize(n + 1);

		visited = vector<bool>();
		visited.resize(n + 1, false);

		for (int i = 0; i < m; ++i)
		{
			int from, to, weight;
			scanf("%d %d %d", &from, &to, &weight);

			adj[from].push_back(Edge(to, weight));
			adj[to].push_back(Edge(from, weight));
		}

		int ans = 0;

		for (Edge next : adj[1])
			ans += dfs(next.to, 1);

		printf("%d\n", ans);
	}

	return 0;
}
