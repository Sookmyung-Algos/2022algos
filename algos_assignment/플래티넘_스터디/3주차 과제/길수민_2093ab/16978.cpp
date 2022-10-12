#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, pi> pipi;

int N, M;
vector<pi> query_one;
vector<pipi> query_two;
int pointer = 0;
ll tree[100005];
ll arr[100005];
vector<ll> ans;

void update (int node, ll value)
{
    while (node <= N) {
        tree[node] += value;
        node += (node & -node);
    }
}

ll sub_query (int node)
{
    ll ret = 0;
   while (node > 0)
   {
       ret += tree[node];
       node -= (node & -node);
   }
    return ret;
}

ll query (int start, int end)
{
    return sub_query(end) - sub_query(start - 1);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        update (i, arr[i]);
    }
    cin >> M;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int index, v;
            cin >> index >> v;
            query_one.push_back ({index, v});
        }
        else
        {
            int k, start, end;
            cin >> k >> start >> end;
            query_two.push_back ({{k, cnt}, {start, end}});
            cnt++;
        }
    }
    ans.resize(query_two.size());
    sort (query_two.begin(), query_two.end());

    for (int i = 0; i < cnt; i++)
    {
        auto cur = query_two[i];

        while (cur.X.X > pointer)
        {
            auto cur_query = query_one[pointer];
            update (cur_query.X, (ll)(cur_query.Y - arr[cur_query.X]));
            arr[cur_query.X] = cur_query.Y;
            pointer++;
        }
        ans[cur.X.Y] = query(cur.Y.X, cur.Y.Y);

    }
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
