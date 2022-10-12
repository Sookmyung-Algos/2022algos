#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 80000

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int n;
int tree[MAX];

bool comp (const pi& a, const pi& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void update (int node)
{
    while (node < MAX)
    {
        tree[node]++;
        node += (node & -node);
    }
}

int query (int node)
{
    int ans = 0;
    while (node > 0)
    {
        ans += tree[node];
        node -= (node & -node);
    }
    return ans;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pi> pos(n);
        set<int> resY;
        set<int> resX;
        vector<int> resXV;
        vector<int> resYV;
        fill (tree, tree+MAX, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> pos[i].first >> pos[i].second;
            resX.insert(pos[i].first);
            resY.insert(pos[i].second);
        }
        for (auto it: resX)
            resXV.push_back (it);
        for (auto it: resY)
            resYV.push_back (it);
        for (int i = 0; i < n; i++)
        {
            pos[i].first = lower_bound(resXV.begin(), resXV.end(), pos[i].first) - resXV.begin();
            pos[i].second = lower_bound(resYV.begin(), resYV.end(), pos[i].second) - resYV.begin();
        }
        sort (pos.begin(), pos.end(), comp);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            pi cur = pos[i];
            ans += i - query (cur.second);
            update (cur.second + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
