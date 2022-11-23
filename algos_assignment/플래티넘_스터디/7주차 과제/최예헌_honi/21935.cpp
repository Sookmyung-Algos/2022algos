#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 200002
#define INF 987654321

int n, m;
vector <int> v[MAX];
bool visited[MAX];
bool nuts[MAX];

void dfs(int node, int par){
    // 현재 노드가 nuts가 아닌 경우
    if (!nuts[node]){
        visited[node] = true;
        for (int i=0; i<v[node].size(); i++){
            if (v[node][i] == par)
                continue;
            
            dfs(v[node][i], node);
        }
    }
    
    // 현재 노드가 nuts인 경우
    else{
        bool flag = false;
        for (int i=0; i<v[node].size(); i++){
            int child = v[node][i];
            
            if (child == par)
                continue;
            
            if (!nuts[child]){
                flag = true;
                nuts[child] = true;
                nuts[node] = false;
                dfs(node, par);
                nuts[child] = false;
                nuts[node] = true;
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b, c;
    
    cin>>n>>m;
    v[1].push_back(0);
    for (int i=0; i<n-1; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=0; i<m; i++){
        cin>>c;
        nuts[c] = true;
    }
    dfs(1, 0);
    
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (visited[i]){
//            cout<<i<<" ";
            cnt++;
        }
    }
    cout<<cnt;
}
