#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 2147000000
 
using namespace std;
 
vector<pair<int, int>> g[MAX];
priority_queue<pair<int, int>> pq;
vector<int> dist(MAX, INF);
int src, dst;
 
void dijkstra() {
    pq.push({0, src});
  
    dist[src] = 0;
  
    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
      
        pq.pop();
 
        if (dist[cur] < cost) {
            continue;
        }
      
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nCost = g[cur][i].second + cost;
          
            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}
 
int main(){
    int n, m, a, b, c;
  
    cin >> n >> m;
  
    while (m--){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
  
    cin >> src >> dst;
    dijkstra();
    cout << dist[dst] << "\n";
  
    return 0;
}
