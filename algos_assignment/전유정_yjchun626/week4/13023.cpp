#include <iostream>
#include <vector>
#define MAX 2000

using namespace std;
 
bool visit[MAX] = { false, };
vector<int> v[MAX];
 
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
	int n, m;
	int a, b;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) 
  {
		cin >> a >> b;
 
		v[a].push_back(b);
		v[b].push_back(a);
	}
 
	for (int i = 0; i < n; i++) 
  {
		dfs(i, 0);
	}
 
	cout << 0;
}
