#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1001;
int n, m;
bool edge[MAX][MAX];
//int group[MAX];
vector<pi> list;
bool no_case;
vector<int> group[2];
bool visit[MAX];
bool dp[MAX][MAX];

void dfs (int node, int id)
{
    visit[node] = true;
    for (auto& it : group[id])
    {
        if (!edge[it][node])
        {
            no_case = true;
            return;
        }
    }
    group[id].push_back (node);
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && !edge[node][i])
            dfs (i, 1 - id);
        if (no_case) return;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n >> m;
    //fill(group, group + MAX, -1);
    for (int i = 0; i < n; i++) edge[i][i] = true;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u - 1][v - 1] = true;
        edge[v - 1][u - 1] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i]) {
            dfs (i, 0);
            if (no_case) {
                cout << "-1\n";
                return 0;
            }
            list.push_back ({group[0].size(), group[1].size()});
            vector<int>().swap(group[0]);
            vector<int>().swap(group[1]);
        }
    }
    int minVal = -1;
    for (int i = 0; i < list.size(); i++)
    {
        if (i == 0)
        {
            dp[i][list[i].first] = true;
            dp[i][list[i].second] = true;
            continue;
        }
        for (int j = 0; j <= n; j++)
        {
            if (dp[i - 1][j])
            {
                if (j + list[i].first <= n) {
                    dp[i][j + list[i].first] = true;
                }
                if (j + list[i].second <= n) {
                    dp[i][j + list[i].second] = true;
                }
            }
        }
    }
    int l_size = list.size() - 1;
    for (int i = 0; i <= n / 2; i++)
    {
        if (dp[l_size][i])
        {
            int firstVal = i;
            int secondVal = n - firstVal;
            if (minVal == -1) minVal = abs(secondVal - firstVal);
            else minVal = min(minVal, abs(secondVal - firstVal));
        }
    }
    cout << minVal << "\n";
    return 0;
}
