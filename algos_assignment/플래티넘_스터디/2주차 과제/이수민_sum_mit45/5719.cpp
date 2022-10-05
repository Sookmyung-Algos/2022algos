//
//  5719.cpp
//  BOJ
//
//  Created by LeeSuMin on 2022/10/05.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
 
vector<pii>g[505];
int dis[505];
vector<int>way[505];
bool check[505];
 
void dijkstra(int x) {
    dis[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, x));
    while (!pq.empty()) {
        int now = pq.top().second;
        int wei = pq.top().first;
        pq.pop();
        if (dis[now] < wei) continue;
        for (int i = 0; i < g[now].size(); i++) {
            if (g[now][i].second == -1)continue;// 두 번째 dijkstra에서 제거된 간선 제외!
            int next = g[now][i].first;
            int ww = g[now][i].second;
            if (dis[now] + ww < dis[next]) {
                dis[next] = dis[now] + ww;
                way[next].clear();
                way[next].push_back(now); // 최단 경로 갱신
                pq.push(make_pair(dis[next], next));
            }
            else if (dis[now] + ww == dis[next]) {
                way[next].push_back(now); // 반드시 이렇게 next와 now를 설정해야 함!
            }
            else continue;
        }
    }
}
 
void bfs(int x) {
    queue<int>q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (check[x] == true) continue;
        check[x] = true;
        for (int i = 0; i < way[x].size(); i++) {
            int nx = way[x][i];
            for (int j = 0; j < g[nx].size(); j++) {
                if (g[nx][j].first == x) g[nx][j].second = -1; // 간선을 삭제
            }
            q.push(nx);
        }
    }
}
 
void init() {
    memset(g, 0, sizeof(g));
    memset(way, 0, sizeof(way));
    memset(dis, 127, sizeof(dis));
    memset(check, false, sizeof(check));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int n, m, start, end, u, v, e;
        init(); // 초기화 시켜주기
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> start >> end;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> e;
            g[u].push_back(make_pair(v, e));
        }
        int INF = dis[0];
        dijkstra(start); // start부터 모든 정점까지의 최단 거리 구함
        bfs(end); // end부터 start까지 연결된 간선들을 제거
        memset(dis, 127, sizeof(dis)); // 최단 거리를 다시 구해야 하므로
        dijkstra(start); // 다시 최단 거리 구함
        if (dis[end] == INF) cout << -1 << "\n";
        else cout << dis[end] << "\n";
    }
}
