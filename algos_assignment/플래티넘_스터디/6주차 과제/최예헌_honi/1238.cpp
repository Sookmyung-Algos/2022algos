#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1002
#define INF 987654321

int n, m, x;
vector <pii> v[1002];
int dijk[1002];
int redijk[1002];

void solve(int s){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    
    for (int i=0; i<=n; i++)
        dijk[i] = INF;
    dijk[s] = 0;
    q.push({0,s});
    
    while (!q.empty()){
        int noww = q.top().first;
        int now = q.top().second;
        q.pop();
        
        if (noww > dijk[now])
            continue;
        
        for (int i=0; i<v[now].size(); i++){
            int next = v[now][i].second;
            int nextw = noww + v[now][i].first;
            
            if (nextw < dijk[next]){
                dijk[next] = nextw;
                q.push({nextw, next});
            }
        }
    }
    
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b, c;
    
    cin>>n>>m>>x;
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        v[a].push_back({c, b});
    }
    
    for (int i=1; i<=n; i++){
        solve(i);
        redijk[i] = dijk[x];
    }
    solve(x);
    
    int result = 0;
    for (int i=1; i<=n ;i++){
        redijk[i] += dijk[i];
        result = max(result, redijk[i]);
    }
    cout<<result;
    return 0;
}
