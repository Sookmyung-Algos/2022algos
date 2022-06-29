#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> visit;

void DFS (int node)
{
    visit[node] = true;
    for (auto &next : edge[node])
    {
        if (!visit[next])
            DFS (next);
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M, ans = 0;
    cin >> N >> M;

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
    {
        if (!visit[i])
        {
            DFS (i);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
