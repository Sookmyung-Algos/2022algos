#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 2147000000
 
using namespace std;
 
vector<pair<int,int>> bus[MAX];
priority_queue<pair<int,int>> pq;
vector<int> dist(MAX,INF);

int n, m, a, b, c, src, dst;
 
void dijkstra(){
  pq.push({0, src});
  dist[src] = 0;
  
  while(!pq.empty()){
      int cost = -pq.top().first;
      int cur = pq.top().second;
      pq.pop();
 
      if(dist[cur] < cost)
        continue;
      
      for(int i = 0; i < bus[cur].size(); i++){
        int next = bus[cur][i].first;
        int ncost = cost + bus[cur][i].second;
        
        if(dist[next] > ncost){
          dist[next] = ncost;
          pq.push({-ncost, next});
        }
      }
  }
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
   
  cin >> n >> m;
  
  while(m--){
    cin >> a >> b >> c;
    bus[a].push_back({b, c});
  }
  
  cin >> src >> dst;
  dijkstra();
  cout << dist[dst];
}


//참고 출처: https://hunidev.tistory.com/24
