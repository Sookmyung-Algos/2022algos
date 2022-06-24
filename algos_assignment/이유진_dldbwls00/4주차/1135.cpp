#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector<vector<int>> adj;
int n; 

int dfs(int cur) {
	vector<int> v;
	int ret = 0;
	int w = adj[cur].size() - 1;

	for (int next : adj[cur]) v.push_back(dfs(next));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) ret = max(ret, v[i] + w--);

	return ret + 1;
}

int main() {
	cin >> n;
	adj.resize(n); 	
	for (int i = 0; i < n; ++i) {
		int p;		
		cin >> p;

		if (p == -1) continue; 		
		adj[p].push_back(i);
	}	
 	int ans = dfs(0); 	 
	cout << ans - 1; 	
	return 0;
}
