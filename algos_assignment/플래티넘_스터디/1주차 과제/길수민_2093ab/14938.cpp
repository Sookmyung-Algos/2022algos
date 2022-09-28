#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;
typedef pair<int, int> pi;

vector<int> arr;
vector<vector<pi>> edge;

int dijkstra (int node, int m)
{
    vector<int> dist (edge.size(), INF);
    priority_queue<pi> pq;
    dist[node] = 0;
    pq.push ({ 0, node });
    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cur_dist) continue;
        for (auto& next : edge[cur])
        {
            int next_dist = cur_dist + next.second;
            int next_node = next.first;
            if (next_dist < dist[next_node] && next_dist <= m)
            {
                dist[next_node] = next_dist;
                pq.push ({ -next_dist,next_node });
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] <= m)
            ans += arr[i];
    }
    return ans;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n, m, r;
    cin >> n >> m >> r;
    arr.resize (n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    edge.resize (n);
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        edge[a - 1].push_back ({ b - 1, l });
        edge[b - 1].push_back ({ a - 1, l });
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max (ans, dijkstra (i, m));
    cout << ans << "\n";
    return 0;
}
