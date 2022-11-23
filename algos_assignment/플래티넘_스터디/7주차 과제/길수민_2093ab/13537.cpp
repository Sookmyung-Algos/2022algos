#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;

class MST {
public:
    vector<int> tree[MAX << 2];
    vector<int> arr;
    int n;

    MST(int _n) {
        n = _n;
        arr.resize (n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        init (0, n - 1, 1);
    }

    void init (int left, int right, int index)
    {
        if (left == right) {
            tree[index].push_back (arr[left]);
            return;
        }
        int mid = (left + right) / 2;
        init (left, mid, index * 2);
        init (mid + 1, right, index * 2 + 1);
        tree[index].resize (tree[index * 2].size() + tree[index * 2 + 1].size());
        merge (tree[index * 2].begin(), tree[index * 2].end(),\
                tree[index * 2 + 1].begin(), tree[index * 2 + 1].end(),\
                tree[index].begin());
    }

    ll query (int left, int right, int index, int start, int end, int k)
    {
        if (left > end || right < start) return 0;
        if (start <= left && right <= end)
            return distance(tree[index].begin(), upper_bound(tree[index].begin(), tree[index].end(), k));
        int mid = (left + right) / 2;
        ll ret1 = query (left, mid, index * 2, start, end, k);
        ll ret2 = query (mid + 1, right, index * 2 + 1, start, end, k);
        return ret1 + ret2;
    }

    ll query (int left, int right, int k)
    {
        return right - left + 1 - query (0, n - 1, 1, left - 1, right - 1, k);
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;
    MST *tree;
    tree = new MST (n);
    int q;
    cin >> q;
    while (q--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        cout << tree->query (i, j, k) << "\n";
    }
    delete tree;
    return 0;
}
