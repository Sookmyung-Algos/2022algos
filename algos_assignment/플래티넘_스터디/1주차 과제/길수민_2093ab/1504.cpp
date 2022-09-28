#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (int)2e9

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int N, E;
vector<vector<pi>> edge;
vector<int> dist;
int v1, v2;
ll ans1, ans2;
void dijkstra (int start, int state)
{
    priority_queue<pi> pq;
    dist.assign (N, INF);
    pq.push ({ 0, start });
    dist[start] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if (cur_dist > dist[cur]) continue;
        for (auto& next: edge[cur])
        {
            int node = next.first;
            int next_dist = cur_dist + next.second;
            if (next_dist < dist[node])
            {
                dist[node] = next_dist;
                pq.push ({ -next_dist, node });
            }
        }
    }
    if (state == 0)
    {
        ans1 += dist[v1 - 1];
        ans2 += dist[v2 - 1];
    }
    else if (state == 1)
    {    
        ans1 += dist[v2 - 1];
        ans2 += dist[N - 1];
    }
    else
    {
        ans1 += dist[N - 1];
        ans2 += dist[v1 - 1];
    }
}
    
int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    
    cin >> N >> E;
    edge.resize (N);
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back ({ b - 1, c });
        edge[b - 1].push_back ({ a - 1, c });
    }
    cin >> v1 >> v2;
    dijkstra (0, 0);
    dijkstra (v1 - 1, 1);
    dijkstra (v2 - 1, 2);
    ll min_dist = min (ans1, ans2);
    if (min_dist >= (ll)INF)
        cout << "-1\n";
    else
        cout << min_dist << "\n";
    return 0;
}
