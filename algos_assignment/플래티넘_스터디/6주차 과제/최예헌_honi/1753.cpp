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
#define MAX 100005
#define INF 987654321

int v, e, k;
vector <pii> arr[20002];
int dijk[20002];

void solve(){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,k});
    
    while(!q.empty()){
        int x = q.top().first;
        int y = q.top().second;
        q.pop();
        
        for (int i=0; i<arr[y].size(); i++){
            int nextx = arr[y][i].first;
            int nextw = arr[y][i].second;
            
            if (x + nextw < dijk[nextx]){
                dijk[nextx] = x + nextw;
                q.push({x + nextw, nextx});
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b, c;
    
    cin>>v>>e>>k;
    for (int i=0; i<e; i++){
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
    }
    
    for (int i=1; i<=v; i++){
        dijk[i] = INF;
    }
    
    dijk[k] = 0;
    solve();
    for (int i=1; i<=v; i++){
        if (dijk[i] == INF)
            cout<<"INF\n";
        else
            cout<<dijk[i]<<"\n";
    }   
}
