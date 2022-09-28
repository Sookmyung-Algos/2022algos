#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9+7

using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int m, n;
vector<vector<int>> map;
vector<vector<int>> dist;

int dijkstra ()
{
    priority_queue<pii> pq;
    if (map[0][0] == -1) return -1;
    pq.push ({-map[0][0], {0, 0}});
    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        pi cur = pq.top().second;
        pq.pop();
        if (cur_dist > dist[cur.first][cur.second])
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny] == -1) continue;
            int next_dist = cur_dist + map[nx][ny];
            if (next_dist < dist[nx][ny])
            {
                dist[nx][ny] = next_dist;
                pq.push ({-next_dist, {nx, ny}});
            }
        }
    }
    if (dist[m - 1][n - 1] == INF) return -1;
    return dist[m - 1][n - 1];
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> m >> n;
    map.assign (m, vector<int>(n));
    dist.assign (m, vector<int>(n, INF));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    cout << dijkstra() << "\n";
    return 0;
}
