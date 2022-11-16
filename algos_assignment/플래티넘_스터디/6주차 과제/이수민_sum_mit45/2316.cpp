#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int INF = 987654321;
const int MAXN = 803;
int city_num, path_num, vertex_num;
int capacity[MAXN][MAXN], flow[MAXN][MAXN];

int MinimumCut(int source, int sink){
  int total_flow = 0;

  while(1){
    vector<int> parent(vertex_num, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);

    while(!q.empty() && parent[sink] == -1){
      int u = q.front();
      q.pop();

      for(int v=2; v<vertex_num ; ++v)
        if(capacity[u][v] - flow[u][v] >0 && parent[v] == -1){
          q.push(v);
          parent[v] = u;
        }
    }

    //더이상 증가 경로가 없는 경우
    if(parent[sink] == -1)
      break;
    
    int amount = INF;
    for(int p = sink; p != source ; p = parent[p])
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    
    for(int p = sink; p != source ; p = parent[p]){
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount; //역 방향은 -flow
    }

    total_flow += amount;
  }
  return total_flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>city_num>>path_num;

  memset(capacity, 0 ,sizeof(capacity));
  memset(flow, 0, sizeof(flow));
  vertex_num = (city_num+1)*2;

  for(int i=2; i<vertex_num ; i +=2)
    capacity[i][i+1] = 1;

  int u, v, u_in, u_out, v_in, v_out;
  for(int i=0; i<path_num ; ++i){
    cin>>u>>v;
    u_in = u *2; u_out = u_in +1;
    v_in = v *2; v_out = v_in + 1;

    capacity[u_out][v_in] = INF;
    capacity[v_out][u_in] = INF;
  }

  int source_out = (1*2) + 1, sink_in = (2*2);
  cout<<MinimumCut(source_out, sink_in)<<"\n";

  return 0;
}
