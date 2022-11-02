#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 9876543210
typedef long long ll;
typedef pair<ll,ll> pll;

ll n,m;
ll dist[502];
vector<pair<pll, ll>> edge;
bool flag = true;

void solve(){
    dist[1] = 0;
    
    for (ll i=1;i<n;i++){
        for (int j=0;j<edge.size();j++){
            ll from = edge[j].first.first;
            ll to = edge[j].first.second;
            ll cost = edge[j].second;
            
            if (dist[from] == MAX)
                continue;
            
            if (dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    }
    
    for (int i=0;i<edge.size();i++){
        ll from = edge[i].first.first;
        ll to = edge[i].first.second;
        ll cost = edge[i].second;
        
        if (dist[from] == MAX)
            continue;
        
        // 음의 사이클이 존재하는 그래프
        if (dist[to] > dist[from] + cost){
            flag = false;
            return;
        }
    }
    
}
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int x,y,z;
    
    cin>>n>>m;
    for (int i=0;i<=n;i++)
        dist[i] = MAX;
    
    while (m--){
        cin>>x>>y>>z;
        edge.push_back({{x,y},z});
    }
    solve();
    
    if (!flag)
        cout<<"-1\n";
    else{
        for (int i=2;i<=n;i++){
            if (dist[i] == MAX)
                cout<<"-1\n";
            else
                cout<<dist[i]<<"\n";
        }
    }
}
