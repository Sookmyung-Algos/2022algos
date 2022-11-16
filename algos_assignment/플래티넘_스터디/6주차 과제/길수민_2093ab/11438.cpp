#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 18;
int N, logN;
int log_parent[MAX][MAX_LOG], depth[MAX];
bool visited[MAX];
vector<vector<int>> edge;

void DFS (int node, int dist)
{
    visited[node] = true;
    depth[node] = dist;
    for (auto& next: edge[node])
    {
        if (visited[next]) continue;
        log_parent[next][0] = node;
        DFS (next, dist + 1);
    }
}

void calc_parent ()
{
    DFS (0, 0); // dist + parent[n][0]
    for (int j = 1; j <= logN; j++)
    {
        for (int i = 0; i < N; i++)
            log_parent[i][j] = log_parent[log_parent[i][j - 1]][j - 1];
    }
}

int LCA (int a, int b)
{
    if (a == 0 || b == 0) return 0;
    if (depth[a] < depth[b]) swap (a, b);

    if (depth[a] != depth[b])
    {
        for (int i = logN; i >= 0; i--)
        {
            if (depth[log_parent[a][i]] >= depth[b])
                a = log_parent[a][i];
        }
    }

    if (a == b) return a;
    for (int i = logN; i >= 0; i--)
    {
        if (log_parent[a][i] != log_parent[b][i])
        {
            a = log_parent[a][i];
            b = log_parent[b][i];
        }
    }
    return log_parent[a][0];
}

int main (void)
{
    ios_base::sync_with_stdio (false); cin.tie (NULL);
    cin >> N;
    edge.resize (N);
    logN = 0;
    int cur = 1;
    while (cur < N){
        logN++;
        cur *= 2;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u - 1].push_back (v - 1);
        edge[v - 1].push_back (u - 1);
    }
    calc_parent();
    int Q;
    cin >> Q;
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA (u - 1, v - 1) + 1 << "\n";
    }
    return 0;
}
