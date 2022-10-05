#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int N;
vector<vector<int>> map;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
const int INF = 1e9;

int dijkstra ()
{
    vector<vector<int>> dist (N, vector<int>(N, INF));
    priority_queue<pii> pq;
    pq.push ({ -map[0][0], {0, 0} });
    while (!pq.empty()) {
        pi cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if (dist[cur.first][cur.second] < cur_dist) continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int next_dist = cur_dist + map[nx][ny];
            if (next_dist < dist[nx][ny]) {
                dist[nx][ny] = next_dist;
                pq.push ({-next_dist, {nx, ny}});
            }
        }
    }
    return dist[N - 1][N - 1];
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int problem = 1;
    while (true)
    {
        cin >> N;
        if (N == 0) break;
        map.assign (N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) cin >> map[i][j];
        }
        cout << "Problem " << problem++ << ": " << dijkstra () << "\n";
    }
    return 0;
}
