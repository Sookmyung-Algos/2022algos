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

int n, m;
int s, e;
int dijk[MAX];
vector <pii> v[100002];

void solve(int s){
    priority_queue<pii> q;
    
    dijk[s] = 0;
    q.push({0, s});
    
    while (!q.empty()){
        int node = q.top().second;
        int dist = -q.top().first;
        q.pop();
        
        if (dijk[node] < dist)
            continue;
        
        for (int i=0; i<v[node].size(); i++){
            int nextn = v[node][i].first;
            int nextd = dist + v[node][i].second;
            
            if (nextd < dijk[nextn]){
                dijk[nextn] = nextd;
                q.push({-nextd, nextn});
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c;
    
    cin>>n>>m;
    for (int i=0; i<=n; i++)
        dijk[i] = INF;
    
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        v[a].push_back({b, c});
    }
    
    cin>>s>>e;
    solve(s);
    cout<<dijk[e];
    return 0;
}
