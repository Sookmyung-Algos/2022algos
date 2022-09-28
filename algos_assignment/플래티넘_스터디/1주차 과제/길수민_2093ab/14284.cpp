#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF (int)1e9

using namespace std;

typedef pair<int, int> pi;

int n, m, s, t;
vector<vector<pi>> edge;

int dijkstra ()
{
    priority_queue<pi> pq;
    vector<int> dist(n, INF);
    dist[s - 1] = 0;
    pq.push ({ 0, s - 1 });
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if (dist[cur] < cur_dist) continue;
          for (auto& it: edge[cur])
        {
            int next = it.first;
            int next_dist = it.second + cur_dist;
            if (dist[next] > next_dist)
            {
                dist[next] = next_dist;
                pq.push ({ -next_dist, next });
            }
        }
    }
    return dist[t - 1];
}

int main (void){    
    ios_base::sync_with_stdio (false);    
    cin.tie (NULL);    
    cout.tie (NULL);    
    cin >> n >> m;    
    edge.resize (n);    
    for (int i = 0; i < m; i++)    
    {        
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back ({ b - 1, c });
        edge[b - 1].push_back ({ a - 1, c });   
    }   
    cin >> s >> t;         
    cout << dijkstra() << "\n";
    return 0;
}
