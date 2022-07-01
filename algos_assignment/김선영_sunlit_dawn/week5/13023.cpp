#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2001;

bool visit[MAX];
bool ans = false;
vector<int> network[MAX];

void dfs(int dep, int node){
    if (dep == 4){
        ans = true;
        return;
    }
    visit[node] = true;
    for (int i = 0; i < network[node].size(); i++){
        int next = network[node][i];
        if (!visit[next]){
            dfs(dep+1 ,next);
        }
    }
    visit[node] = false;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;        
        network[u].push_back(v);
        network[v].push_back(u);
    }
    
    for(int i = 0; i<n;i++){
        dfs(0, i);
        if (ans == true) break;
    }
    if (ans == true) cout << 1;
    else cout << 0;
}
