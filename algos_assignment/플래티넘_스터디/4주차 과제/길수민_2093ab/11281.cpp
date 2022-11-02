#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> edge;
int id, cur_group;
vector<vector<int>> SCC;
stack<int> s;
int seq[20002];
bool finished[20002];
int group_id[20002];

int dfs (int node)
{
    seq[node] = ++id;
    s.push (node);

    int parent = seq[node];
    for (auto& next: edge[node])
    {
        if (!seq[next]) parent = min (parent, dfs (next));
        else if(!finished[next]) parent = min (parent, seq[next]);
    }

    if (parent == seq[node])
    {
        cur_group++;
        vector<int> scc;
        while (true)
        {
            int topNode = s.top();
            s.pop();
            scc.push_back (topNode);
            group_id[topNode] = cur_group;
            finished[topNode] = true;
            if (topNode == node) break;
        }
        SCC.push_back (scc);
    }
    return parent;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    edge.resize (2 * N);
    for (int i = 0; i < M; i++)
    {
        int u, v, notu, notv;
        cin >> u >> v;
        if (u < 0) {
            u = N - 1 - u;
            notu = u - N;
        }
        else {
            u = u - 1;
            notu = u + N;
        }
        if (v < 0) {
            v = N - 1 - v;
            notv = v - N;
        }
        else {
            v = v - 1;
            notv = v + N;
        }
        edge[notu].push_back (v);
        edge[notv].push_back (u);
    }
    for (int i = 0; i < 2 * N; i++)
    {
        if (!finished[i]) dfs (i);
    }
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        if (group_id[i] == group_id[i + N])
        {
            flag = false;
            break;
        }
    }
    cout << flag << "\n";
    if (flag)
    {
        for (int i = 0; i < N; i++)
        {
            if (group_id[i] < group_id[i + N])
                cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
