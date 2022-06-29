#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> visit;
bool ans = false;
int N, M;

void DFS (int node, int depth)
{
    if (depth == 4)
    {
        ans = true;
        return;
    }
    visit[node] = 1;
    for (auto& next : edge[node])
    {
        if (!visit[next])
            DFS (next, depth + 1);
        if (ans)
            return;
    }
    visit[node] = 0;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    edge.resize (N);
    visit.resize (N, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }
    for (int i = 0; i < N; i++)
    {
        DFS(i, 0);
        if (ans)
            break;
    }
    cout << ans << "\n";
    return 0;
}
