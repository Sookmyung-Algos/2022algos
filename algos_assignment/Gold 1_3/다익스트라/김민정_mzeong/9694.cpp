#include <bits/stdc++.h>
#define INF 81
using namespace std;

vector<pair<int, int>> graph[20];
int d[20], p[20];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (d[now] < dist) continue;
        
        for (auto nxt : graph[now]) {
            int cost = dist + nxt.second;
            if (cost < d[nxt.first]) {
                d[nxt.first] = cost;
                pq.push({-cost, nxt.first});
                p[nxt.first] = now;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    for (int c = 1; c <= t; c++) {
        for (int i = 0; i < 20; i++) graph[i].clear();
        
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int x, y, z; cin >> x >> y >> z;
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});
        }
        fill(d, d+20, INF); 
        fill(p, p+20, -1);
        dijkstra(0);
        
        cout << "Case #" << c << ": ";
        if (d[m-1] == INF) { cout << -1 << "\n"; continue; }
        
        stack<int> s; int i = m-1;
        while (i != -1) {
            s.push(i); i = p[i];
        }
        while (!s.empty()) {
            cout << s.top() << " "; s.pop();
        }
        cout << "\n";
    }
    return 0;
}
