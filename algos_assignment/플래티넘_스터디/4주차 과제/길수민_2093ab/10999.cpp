#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, M, K;

class SegTree {
    ll tree[MAX * 4];
    ll lazy[MAX * 4];
    ll arr[MAX];
public:
    SegTree ()
    {
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        init (0, N - 1, 1);
    }

    ll init (int left, int right, int node)
    {
        lazy[node] = 0;
        if (left == right) return tree[node] = arr[left];
        int mid = (left + right) / 2;
        ll l_ret = init (left, mid, node * 2);
        ll r_ret = init (mid + 1, right, node * 2 + 1);
        return tree[node] = l_ret + r_ret;
    }

    void update_lazy (int left, int right, int node)
    {
        if (lazy[node] != 0) {
            tree[node] += (ll)(right - left + 1) * lazy[node];
            if (left != right) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range (int left, int right, int node, int q_l, int q_r, ll diff)
    {
        update_lazy (left, right, node);

        if (q_l > right || q_r < left) return;
        if (q_l <= left && right <= q_r) {
            tree[node] += (ll)(right - left + 1) * diff;
            if (left != right) {
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }

        int mid = (left + right) / 2;
        update_range (left, mid, node * 2, q_l, q_r, diff);
        update_range (mid + 1, right, node * 2 + 1, q_l, q_r, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query (int left, int right, int node, int q_l, int q_r) {
        update_lazy (left, right, node);
        if (q_l > right || q_r < left) return 0;

        if (q_l <= left && right <= q_r) return tree[node];

        int mid = (left + right) / 2;
        ll l_ret = query (left, mid, node * 2, q_l, q_r);
        ll r_ret = query (mid + 1, right, node * 2 + 1, q_l, q_r);
        return l_ret + r_ret;
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M >> K;
    SegTree *tree;
    tree = new SegTree;
    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            ll d;
            cin >> d;
            tree->update_range (0, N - 1, 1, b-1, c-1, d);
        } else {
            cout << tree->query (0, N - 1, 1, b - 1, c - 1) << "\n";
        }
    }
    delete tree;
    return 0;
}
