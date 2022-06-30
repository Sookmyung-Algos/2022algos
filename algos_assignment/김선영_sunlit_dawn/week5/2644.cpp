#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 101;
using namespace std;

bool visit[MAX];
vector<int> people[MAX];
int cnt=0;

void dfs(int node, int a){
    visit[node] = true;
    for (int i = 0; i < people[node].size(); i++){
        int next = people[node][i];
        if (next == a){
          visit[next] = true;
          cnt++;
          return;
        }
        else if (!visit[next]){
            dfs(next, a);
            cnt++;
        }
    }
}

int main(){
    int n, m;
    cin >> n;
    
    int a,b;
    cin >> a >> b;
    
    cin >> m;
    for (int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        people[u].push_back(v);
        people[v].push_back(u);        
    }
    
    int temp;
    if (a > b){
        dfs(b, a);
        temp = a;
    }    
    else {
        dfs(a,b);
        temp = b;
    }
     
    if (!visit[temp]) cout << -1;
    else cout << cnt;
}
