#include <iostream>
#include <vector>
using namespace std; 

int visit[2001]; 
vector <int> graph[2001]; 
int n, m; 
bool res=false; 

void dfs(int node,int count) {
	if (count == 4) {
		res = true; 
		return; 
	}
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i]; 
		if (visit[next]==0 && res==false) {
			dfs(next,count+1); 
		}
	}
	visit[node] = false; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; 
		graph[a].push_back(b);
		graph[b].push_back(a); 
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0); 
		if (res) break; 
	}

	cout << res; 

	

	return 0; 
}
