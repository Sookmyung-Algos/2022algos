#include <bits/stdc++.h>
#define INF 6250000
using namespace std;

int n, m, sy, sx, fy, fx, Garbage = 2500;
int Map[50][50], d[50][50];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {sy, sx}});
    d[sy][sx] = 0;
    
    while (!pq.empty()) {
        int g = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if (y == fy && x == fx) {
            cout << d[fy][fx] / Garbage << " " << d[fy][fx] % Garbage;
            return;
        }
        if (d[y][x] < g) continue;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            
            int ng = g + Map[ny][nx];
            if (ng < d[ny][nx]) {
                d[ny][nx] = ng;
                pq.push({-ng, {ny, nx}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'S') sy = i, sx = j;
            else if (c == 'F') fy = i, fx = j;
            else if (c == 'g') {
                Map[i][j] = Garbage;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (Map[ni][nj] == Garbage) continue;
                    Map[ni][nj] = 1;
                }
            }
            d[i][j] = INF;
        }
    }
    Map[sy][sx] = 0, Map[fy][fx] = 0;
    dijkstra();
    return 0;
}
