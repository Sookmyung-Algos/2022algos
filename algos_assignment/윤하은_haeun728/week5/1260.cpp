#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, V;
int check[1001];                                            

void dfs(int, vector<vector<int>>);
void bfs(int, vector<vector<int>>, queue<int>);

int main() 
{
	cin >> N >> M >> V;
	vector<vector<int>>v(N+1);                            
	queue<int>q;                                           

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);                                   
		v[b].push_back(a);                                  
	}

	for (int i = 1; i <= N; i++)                             
		sort(v[i].begin(), v[i].end());

	dfs(V, v);

	for (int i = 1; i <= N; i++)                            
		check[i] = 0;
	cout << "\n";

	bfs(V, v, q);

}

void dfs(int V, vector<vector<int>>v) {
	check[V] = 1;                                        
	cout << V << " ";                                    
	for (int i = 0; i < v[V].size(); i++) {             
		if (check[v[V][i]] == 0) {                           
			dfs(v[V][i], v);
		}
	}
}

void bfs(int V, vector<vector<int>>v, queue<int>q) {
	q.push(V);                                              
	check[V] = 1;                                           
	while (!q.empty())
	{
		int sol = q.front();
		cout << sol << " ";                                  
		for (int i = 0; i < v[sol].size(); i++) {          
			if (check[v[sol][i]] == 0) {
				q.push(v[sol][i]);
				check[v[sol][i]] = 1;
			}
		}
		q.pop();
	}
}
