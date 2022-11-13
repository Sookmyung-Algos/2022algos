#include<iostream>
#include<vector>
#include<cstring>

#define MAX 501
#define INF 1e9

using namespace std;

vector<pair<pair<int,int>,int>> adj;
int dist[MAX];

void belmanford(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<adj.size();j++){
            int s=adj[j].first.first;
            int e=adj[j].first.second;
            int t=adj[j].second;
            
            if(dist[s]+t<dist[e])
                dist[e]=dist[s]+t;
        }
    }
    
    for(int i=0;i<adj.size();i++){
        int s=adj[i].first.first;
        int e=adj[i].first.second;
        int t=adj[i].second;
        
        if(dist[s]+t<dist[e]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    int tc, m,n,w;
    cin>>tc;
    
    while(tc--){
        memset(dist, INF, sizeof(dist));
        adj.clear();
        cin>> n >> m >>w;
        for(int i=0;i<m;i++){
            int s,e,t;
            cin>>s>>e>>t;
            adj.push_back({{s,e},t});
            adj.push_back({{e,s},t});
        }
        
        for(int i=0;i<w;i++){
            int s,e,t;
            cin>>s>>e>>t;
            adj.push_back({{s,e},-t});
        }
        
        belmanford(n);
    }
    
    return 0;
}
