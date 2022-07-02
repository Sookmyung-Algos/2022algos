#include <iostream>
#include <vector>
#include <cstring> //memset 사용 위함. 
using namespace std; 

int visit[100001]; 
vector <pair<int,int>> graph[100001]; 
int n,startnode; 
int maxdist = 0; 

void dfs(int node,int dist) {
	if (visit[node]) return; 
	if (maxdist < dist) {
		maxdist = dist; 
		startnode = node; 
	}

	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first; 
		dfs(next,dist+graph[node][i].second); 
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int v; 
		cin >> v;
		
		int a,c; 
		while (cin >> a) {
			if (a == -1) break; 
			cin >> c; 
			graph[v].push_back({ a,c }); 
			graph[a].push_back({ v,c }); 
		}

	}
	
	dfs(1, 0); 
	memset(visit, 0, sizeof(visit));
	maxdist = 0; 
	dfs(startnode, 0); 

	cout << maxdist << '\n'; 

	return 0; 
}
