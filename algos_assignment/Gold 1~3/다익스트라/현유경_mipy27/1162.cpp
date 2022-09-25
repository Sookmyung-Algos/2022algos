#include <iostream>
#include <vector>
#include <queue>
#define INF 1e15
 
using namespace std;
typedef long long ll;
 
int n, m, k;
ll ans = INF;
 
ll costs[10001][21]; // 포장해서 가는 최소 비용
vector<vector<pair<int, int>>> edges;

void dijkstra(){
    
    // initial
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            costs[i][j] = INF;
        }
    }
    
    priority_queue<pair<ll, pair<int, int>> > pq; // cost, node, cnt
    pq.push({0, {1, 0}});  // 초기값 설정
    costs[1][0] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second.first;
        int cnt = pq.top().second.second;
        ll cost = -pq.top().first; // 적은 것이 먼저 오도록 음수화
        pq.pop();
        
        // 저장된 비용이 더 효율적이면 continue
        if (costs[node][cnt]<cost) continue;
        
        // 저장된 비용이 더 효율적이지 않으면 반복문 실행
        for(int i=0; i<edges[node].size(); i++){
            int next_node = edges[node][i].first;
            ll next_cost = cost + edges[node][i].second; // 새로운 비용 계산
            
            // 포장하지 않는 경우
            if(costs[next_node][cnt] > next_cost){
                costs[next_node][cnt] = next_cost;  // 비용 갱신
                pq.push({-next_cost, {next_node, cnt}});
            }
            
            // 포장할 경우 (포장할 경우 이동 비용은 0)
            if(costs[next_node][cnt+1] > cost && cnt+1 <= k){
                costs[next_node][cnt+1] = cost;
                pq.push({-cost, {next_node, cnt+1}}); // 포장 횟수 갱신
            }
        }
    }
}
 
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    edges.resize(n+1);
    
    // 도로가 연결하는 두 도시 a,b
    // 도로를 통과하는데 걸리는 시간 c
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    
    dijkstra();
    
    for(int i=0; i<=k; i++) ans = min(ans, costs[n][i]);
    cout << ans << endl;
}
