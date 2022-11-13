#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e15
using namespace std;
typedef long long ll;

int N, M, K;
ll dis[10005][21]; // dis[v][k] v번 도시까지 k개의 도로를 포장해서 가는 최단거리
vector<pair<int, int>> adj[10005];
void dijkstra(int s);

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> M >> K;
   for (int i = 0; i < M; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({ b,c });
      adj[b].push_back({ a,c });
   }

   dijkstra(1);
   ll ans = INF;
   for (int i = 0; i <= K; i++)
      ans = min(ans, dis[N][i]);
   cout << ans;
   return 0;
}

void dijkstra(int s) {
   
   for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= K; j++) {
         dis[i][j] = INF;
      }
   }

   priority_queue<pair<ll, pair<int, int>>> pq; // cost, pos, 포장
   dis[s][0] = 0;
   pq.push({ 0,{ s,0 } });

   while (!pq.empty()) {
      ll cost = -pq.top().first;
      int node = pq.top().second.first;
      int cnt = pq.top().second.second;
      pq.pop();



      if (cost > dis[node][cnt])
         continue;

      for (int i = 0; i < adj[node].size(); i++) {
         int node2 = adj[node][i].first;
         int cost2 = adj[node][i].second;

         // 포장
         if (dis[node2][cnt+1] > dis[node][cnt] && cnt < K) {
            dis[node2][cnt+1] = dis[node][cnt];
            pq.push({ -dis[node2][cnt+1], { node2, cnt+1 } });
         }
         // 포장 X
         if (dis[node2][cnt] > dis[node][cnt] + cost2) {
            dis[node2][cnt] = dis[node][cnt] + cost2;
            pq.push({ -dis[node2][cnt], { node2, cnt } });
         }
      }
   }
}
