#include <iostream>
#include <vector>
#include <queue>
 
#define pii pair<int, int>
 
using namespace std;
 
 
int N, M, X;
const int INF = 1e9+7;
vector<pii > graph[1001]; 
vector<int> dist;
int resdist[1001];
 
void input(){
    int u, v, t;
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> t;
        graph[u].push_back(make_pair(t, v));
    }
}
 
void Dijstra(int S){
    dist.clear();
    dist.resize(N+1, INF);
    
    dist[S] = 0;
    
    priority_queue<pii, vector<pii >, greater<pii > > que;
    que.push({0, S});
    
    while(!que.empty()){
        int min_cost = que.top().first;
        int now = que.top().second;
        que.pop();
        
        if(min_cost > dist[now]) continue;
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].second;
            int next_cost = min_cost + graph[now][i].first;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    for(int i = 1; i <= N; i++){
        Dijstra(i);
        // i가 X로 가는 최단거리 half
        resdist[i] = dist[X];
    }
    Dijstra(X);
    int res = 0;
    for(int i = 1; i <= N; i++){
        resdist[i] += dist[i];
        res = max(res, resdist[i]);
    }
    
    cout << res;
    
    return 0;
}
