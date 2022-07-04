#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
struct QUESTION { int x, y, a, b; };

int n, q;
ll arr[100001];
vector<QUESTION> cmd;
vector<ll> seg;

ll make_seg(int node, int s, int e) {
    if (s == e) return seg[node] = (ll)(arr[s]);
    
    int mid = (s + e) / 2;
    ll left = make_seg(node * 2, s, mid);
    ll right = make_seg(node * 2 + 1, mid + 1, e);
    
    return seg[node] = left + right;
}

ll sectionSum(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) return seg[node];
    
    int mid = (s + e) / 2;
    ll left = sectionSum(node * 2, s, mid, l, r);
    ll right = sectionSum(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

void update(int node, int s, int e, int idx, ll diff) {
    if (idx < s || idx > e) return;
    seg[node] = seg[node] + diff;
    
    if (s != e) {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, diff);
        update(node * 2 + 1, mid + 1, e, idx, diff);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--;
        cmd.push_back({x, y, a, b});
    }
    
    int height = (int)ceil(log2(n));
    int size = (1 << (height + 1));
    seg.resize(size);
    make_seg(1, 0, n-1);
    
    for (int i = 0; i < cmd.size(); i++) {
        int x = cmd[i].x;
        int y = cmd[i].y;
        int a = cmd[i].a;
        int b = cmd[i].b;
        
        if (x > y) swap(x, y);
        cout << sectionSum(1, 0, n-1, x, y) << "\n";
        
        ll diff = b - arr[a];
        arr[a] = b;
        update(1, 0, n-1, a, diff);
    }
}
