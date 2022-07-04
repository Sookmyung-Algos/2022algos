#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> seg;
vector<pair<int, int>> cmd;

int make_seg(int node, int s, int e) {
    if (s == e) {
        seg[node] = arr[s];
        return seg[node];
    }
    
    int mid = (s + e) / 2;
    int left = make_seg(node * 2, s, mid);
    int right = make_seg(node * 2 + 1, mid + 1, e);
    seg[node] = min(left, right);
    
    return seg[node];
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 2e9;
    if (l <= s && e <= r) return seg[node];
    
    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);
    return min(left, right);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cmd.push_back({a, b});
    }
    
    int height = (int)ceil(log2(n));
    int size = (1 << (height + 1));
    seg.resize(size);
    
    make_seg(1, 0, n-1);
    for (int i = 0; i < cmd.size(); i++) {
        int idx1 = cmd[i].first - 1;
        int idx2 = cmd[i].second - 1;
        cout << query(1, 0, n-1, idx1, idx2) << "\n";
    }
}
