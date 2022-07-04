#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll ans;
vector<int> vec[2001];
vector<int> seg;

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) return seg[node];
    
    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

void update(int node, int s, int e, int val) {
    if (s == e) {
        seg[node] += 1;
        return;
    }
    
    int mid = (s + e) / 2;
    if (val <= mid) update(node * 2, s, mid, val);
    else update(node * 2 + 1, mid + 1, e, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
    }
    
    int height = (int)ceil(log2(n));
	int size = (1 << (height + 1));
	seg.resize(size);
	
	for (int i = 1; i <= n; i++) {
	    for (int j = 0; j < vec[i].size(); j++) {
	        int x = vec[i][j];
	        ans += query(1, 1, n, x+1, n);
	    }
	    for (int j = 0; j < vec[i].size(); j++) {
	        int x = vec[i][j];
	        update(1, 1, n, x);
	    }
	}
    cout << ans;
}
