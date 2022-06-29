#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;
vector<int> visit;

void DFS (int node)
{
    cout << node << " ";
    visit[node] = 1;
    for (auto& next : edge[node])
    {
        if (!visit[next])
            DFS (next);
    }
}

void BFS (int node)
{
    queue<int> q;

    q.push (node);
    visit[node] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (auto& next : edge[cur])
        {
            if (!visit[next])
            {
                q.push (next);
                visit[next] = 1;
            }
        }
    }
    cout << "\n";
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M, V;
    cin >> N >> M >> V;
    edge.resize (N + 1);
    visit.assign (N + 1, 0);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back (v);
        edge[v].push_back (u);
    }
    for (int i = 1; i <= N; i++)
        sort (edge[i].begin(), edge[i].end());
    DFS (V);
    cout << "\n";
    visit.assign (N + 1, 0);
    BFS (V);
    return 0;
}
