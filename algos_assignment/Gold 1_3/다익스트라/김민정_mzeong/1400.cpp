#include <bits/stdc++.h>
#define INF 6250000
using namespace std;

int m, n, ay, ax, by, bx, Crossroad = 400, cnt;
int Map[20][20], d[20][20];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<int, pair<int, int>>> v;

int check(int t, int d) {
    if (t / Crossroad) {
        int num = t / Crossroad - 1;
        int dir = v[num].first;
        int a = v[num].second.first, b = v[num].second.second;
        t %= Crossroad;
        
        if (d == dir) {
            if (t % (a + b) == 0) return t + 1;
            else if (t % (a + b) <= a) return t;
            else return (t / (a + b) + 1) * (a + b) + 1;
        }
        else {
            if (t % (a + b) > a || t % (a + b) == 0) return t;
            else return t + a - (t % (a + b)) + 1;
        }
    }
    else return t;
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {ay, ax}});
    d[ay][ax] = 0;
    
    while (!pq.empty()) {
        int t = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if (y == by && x == bx) break;
        if (d[y][x] < t) continue;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (!(ny == ay && nx == ax) && Map[ny][nx] == 0) continue; 
            
            int nt = check(t + Map[ny][nx], i % 2);
            if (nt < d[ny][nx]) {
                d[ny][nx] = nt;
                pq.push({-nt, {ny, nx}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    while (1) {
        cin >> m >> n; if (m == 0 && n == 0) break;
        
        memset(Map, 0, sizeof(Map));
        v.clear();
        cnt = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c; cin >> c;
                if (c == '#') Map[i][j] = 1;
                else if (c == 'A') ay = i, ax = j;
                else if (c == 'B') by = i, bx = j, Map[i][j] = 1;
                else if ('0' <= c && c <= '9') cnt++, Map[i][j] = 1 + Crossroad*(c-'0'+1);
                d[i][j] = INF;
            }
        }
        for (int i = 0; i < cnt; i++) {
            int num, a, b; char dir; cin >> num >> dir >> a >> b;
            if (dir == '-') v.push_back({0, {a, b}});
            else v.push_back({1, {b, a}});
        }
        dijkstra();
        if (d[by][bx] == INF) cout << "impossible\n";
        else cout << d[by][bx] << "\n";
    }
    return 0;
}
