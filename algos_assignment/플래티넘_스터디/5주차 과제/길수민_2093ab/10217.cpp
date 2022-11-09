#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, M, K;
vector<vector<pii>> edge;
int dp[10001][101];

int dijkstra ()
{
    priority_queue<pii> pq;
    pq.push ({ 0, {0, 0} });
    dp[0][0] = 0;
    while (!pq.empty()) {
        int cur_node = pq.top().second.first;
        int cur_dist = -pq.top().first;
        int cur_cost = pq.top().second.second;
        pq.pop();
        if (dp[cur_cost][cur_node] < cur_dist) continue;
        for (auto& next: edge[cur_node])
        {
            int next_node = next.first;
            int next_cost = next.second.first + cur_cost;
            int next_dist = next.second.second + cur_dist;
            if (next_cost > M) continue;
            if (dp[next_cost][next_node] == -1 || \
                    dp[next_cost][next_node] > next_dist)
            {
                dp[next_cost][next_node] = next_dist;
                pq.push ({ -next_dist, { next_node, next_cost }});
            }
        }
    }
    int minVal = -1;
    for (int i = 0; i <= M; i++)
    {
        if (minVal == -1 && dp[i][N - 1] != -1)
            minVal = dp[i][N - 1];
        else if (dp[i][N - 1] != -1)
            minVal = min (dp[i][N - 1], minVal);
    }
    return minVal;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
        vector<vector<pii>>().swap (edge);
        edge.resize (N);
        memset (dp, -1, sizeof(dp));
        for (int i = 0; i < K; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            edge[u - 1].push_back ({v - 1, {c, d}});
        }
        int ret = dijkstra ();
        if (ret == -1) cout << "Poor KCM\n";
        else cout << ret << "\n";
    }
    return 0;
}
