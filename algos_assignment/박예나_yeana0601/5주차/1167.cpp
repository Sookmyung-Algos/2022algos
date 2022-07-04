#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
struct Node
{
    int index;
    int dist;
};
int v, maxDist, maxNode;
bool visit[100001];
vector<Node> graph[100001];

void dfs(int node, int dist)
{
    if (visit[node])
        return;
    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = node;
    }
    visit[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextIndex = graph[node][i].index;
        int nextDist = graph[node][i].dist;
        dfs(nextIndex, nextDist + dist);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> v;
    int fr, to, dist;
    for (int i = 1; i < v + 1; i++)
    {
        cin >> fr;
        while (true)
        {
            cin >> to;
            if (to == -1)
                break;
            cin >> dist;
            graph[fr].push_back({to, dist});
            graph[to].push_back({fr, dist});
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist << '\n';
    return 0;
}
