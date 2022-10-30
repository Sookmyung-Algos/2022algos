#include <bits/stdc++.h>
using namespace std;
const int INF = 10001;

struct Edge {
    int s, e, t;
    Edge(int a, int b, int c) {
        s = a; e = b; t = c;
    }
};
vector<Edge> Ed;
int dist[501];
int n, m, w, s, e, t;


bool BellmanFord() {
    dist[1] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < Ed.size(); j++) {
            auto [u, v, w] = Ed[j];
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w; // 시작점이 주어지지 않으므로 시작점과 연결된 경로가 있는지 확인하는 dist[u] != INF 부분 필요 없음
        }
    }
    for (int j = 0; j < Ed.size(); j++) { 
        auto [u, v, w] = Ed[j];
        if (dist[u] + w < dist[v]) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        Ed.clear();
        for (int i = 1; i <= n; i++) dist[i] = INF;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            Ed.push_back(Edge(s, e, t));
            Ed.push_back(Edge(e, s, t));
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            Ed.push_back(Edge(s, e, -t));
        }
        cout << (BellmanFord() ? "YES\n" : "NO\n");
    }
    return 0;
}
