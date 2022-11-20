#include <bits/stdc++.h>
using namespace std;
const int n_ = 1e7;

int A[n_], tree[n_], dp[n_];

int query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
}

void update(int node, int s, int e, int idx, int val) {
    if (idx < s || e < idx) return;
    if (s == e) tree[node] = val;
    else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, val);
        update(node * 2 + 1, mid + 1, e, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); 
  
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = query(1, 1, 1000000, 1, A[i] - 1) + 1;
        update(1, 1, 1000000, A[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
