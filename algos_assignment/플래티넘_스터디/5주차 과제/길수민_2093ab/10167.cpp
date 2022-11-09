#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 3003;
const int MOD = 1e9 + 7;
const ll INF = 1e15;
int N;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<int> x_pos;
vector<int> y_pos;
vector<pii> pos;

struct Node {
    ll lval, rval, val, all;
};

class SegTree {
public:
    Node tree[MAX << 2];
    SegTree () {
        for (int i = 0; i < MAX * 4; i++)
        {
            tree[i].all = 0;
            tree[i].lval = -INF;
            tree[i].rval = -INF;
            tree[i].val = -INF;
        }
    }
   
    Node update (int left, int right, int node, int idx, ll diff)
    {
        if (left > idx || idx > right) return tree[node];
        if (left == right) {
            if (tree[node].lval == -INF) {
                tree[node].lval = diff;
                tree[node].rval = diff;
                tree[node].all = diff;
                tree[node].val = diff;
                return tree[node];
            }
            tree[node].lval += diff;
            tree[node].rval += diff;
            tree[node].val += diff;
            tree[node].all += diff;
            return tree[node];
        }
        int mid = (left + right) / 2;
        Node l_ret = update (left, mid, node * 2, idx, diff);
        Node r_ret = update (mid + 1, right, node * 2 + 1, idx, diff);
        tree[node].lval = max (l_ret.lval, l_ret.all + r_ret.lval);
        tree[node].rval = max (r_ret.rval, r_ret.all + l_ret.rval);
        tree[node].val = max (max (l_ret.val, r_ret.val), l_ret.rval + r_ret.lval);
        tree[node].all = l_ret.all + r_ret.all;
        return tree[node];
    }

    Node query (int left, int right, int node, int start, int end)
    {
        if (left > end || right < start) return {-INF, -INF, -INF, 0};
        if (start <= left && right <= end) return tree[node];
        int mid = (left + right) / 2;
        Node l_ret = query (left, mid, node * 2, start, end);
        Node r_ret = query (mid + 1, right, node * 2 + 1, start, end);
        Node ans;
        ans.lval = max (l_ret.lval, l_ret.all + r_ret.lval);
        ans.rval = max (r_ret.rval, r_ret.all + l_ret.rval);
        ans.val = max (max (l_ret.val, r_ret.val), l_ret.rval + r_ret.lval);
        ans.all = l_ret.all + r_ret.all;
        return ans;
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    pos.resize (N);
    for (int i = 0; i < N; i++)
    {
        cin >> pos[i].X.X >> pos[i].X.Y >> pos[i].Y;
        x_pos.push_back (pos[i].X.X);
        y_pos.push_back (pos[i].X.Y);
    }
    sort (x_pos.begin(), x_pos.end());
    sort (y_pos.begin(), y_pos.end());
    x_pos.erase (unique (x_pos.begin(), x_pos.end()), x_pos.end());
    y_pos.erase (unique (y_pos.begin(), y_pos.end()), y_pos.end());
    for (int i = 0; i < N; i++)
    {
        pos[i].X.X = distance (x_pos.begin(), lower_bound (x_pos.begin(), x_pos.end(), pos[i].X.X));
        pos[i].X.Y = distance (y_pos.begin(), lower_bound (y_pos.begin(), y_pos.end(), pos[i].X.Y));
    }
    sort (pos.begin(), pos.end(), [](pii a, pii b) {
                if (a.X.Y == b.X.Y) return a.X.X < b.X.X;
                return a.X.Y < b.X.Y;
            });
    vector<pi> y_list;
    y_list.push_back ({pos[0].X.Y, 0});
    for (int i = 1; i < N; i++)
    {
        if (pos[i - 1].X.Y != pos[i].X.Y)
            y_list.push_back ({pos[i].X.Y, i});
    }
    y_list.push_back ({ 3003, N });
    ll ans = 0;
    for (int sy = 0; sy < y_list.size() - 1; sy++)
    {
        SegTree *tree;
        tree = new SegTree ();
        for (int ey = sy; ey < y_list.size() - 1; ey++)
        {
            int start = y_list[ey].Y;
            int end = y_list[ey + 1].Y;
            for (int i = start; i < end; i++)
            {
                tree->update (0, MAX - 1, 1, pos[i].X.X, pos[i].Y);
            }
            Node ret = tree->query (0, MAX - 1, 1, 0, MAX - 1);
            ans = max (ans, ret.val);
        }
        delete tree;
    }
    cout << ans << "\n";
    return 0;
}

