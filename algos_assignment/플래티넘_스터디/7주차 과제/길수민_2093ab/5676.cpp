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
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, K;

class SegTree {
public:
    int tree[MAX * 4];
    int arr[MAX];
    int n;
    SegTree (int _n) {
        n = _n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] == 0) arr[i] = 0;
            else arr[i] = -1;
        }
        init (0, n - 1, 1);
    }

    int init (int left, int right, int node)
    {
        if (left == right) return tree[node] = arr[left];
        int mid = (left + right) / 2;
        int ret1 = init (left, mid, node * 2);
        int ret2 = init (mid + 1, right, node * 2 + 1);
        return tree[node] = ret1 * ret2;
    }

    int update (int left, int right, int node, int idx)
    {
        if (left > idx || right < idx) return tree[node];
        if (left == right && left == idx) return tree[node] = arr[idx];
        int mid = (left + right) / 2;
        int ret1 = update (left, mid, node * 2, idx);
        int ret2 = update (mid + 1, right, node * 2 + 1, idx);
        return tree[node] = ret1 * ret2;
    }

    int query (int left, int right, int node, int start, int end)
    {
        if (start > right || end < left) return 1;
        if (start <= left && right <= end) return tree[node];
        int mid = (left + right) / 2;
        int ret1 = query (left, mid, node * 2, start, end);
        int ret2 = query (mid + 1, right, node * 2 + 1, start, end);
        return ret1 * ret2;
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    while (cin >> N >> K)
    {
        SegTree *tree;
        tree = new SegTree(N);
        for (int i = 0; i < K; i++)
        {
            char query;
            int a, b;
            cin >> query >> a >> b;
            if (query == 'C')
            {
                if (b > 0) tree->arr[a - 1] = 1;
                else if (b == 0) tree->arr[a - 1] = 0;
                else tree->arr[a - 1] = -1;
                tree->update (0, N - 1, 1, a - 1);
            }
            else
            {
                int ret = tree->query (0, N - 1, 1, a - 1, b - 1);
                if (ret < 0) cout << "-";
                else if (ret == 0) cout << "0";
                else cout << "+";
            }
        }
        cout << "\n";
        delete tree;
    }
    return 0;
}
