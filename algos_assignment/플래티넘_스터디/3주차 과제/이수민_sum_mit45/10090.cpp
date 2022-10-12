#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX 10000003
using namespace std;

ll N;
ll tree[MAX];
vector <pair<ll, ll>> v;

ll init(ll N, ll s, ll e) {
	if (s == e) return tree[N] = 0;
	ll mid = (s + e) / 2;
	return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

void update(ll N, ll s, ll e, ll idx) {
	if (idx > e || idx < s) return;

	if (s == e) {
		if (idx == s) tree[N]++ ;
		return;
	}

	ll mid = (s + e) / 2;
	update(N * 2, s, mid, idx);
	update(N * 2 + 1, mid + 1, e, idx);
	tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

ll query(ll N, ll s, ll e, ll l, ll r) {
	if (l > e || r < s)return 0;
	if (l <= s && e <= r) return tree[N];

	ll mid = (s + e) / 2;
	return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
}

int main() {
	cin >> N;
	for (ll i = 1; i <= N; i++) {
		ll x; cin >> x;
		v.push_back(make_pair(x,i));
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	ll ans = 0;
	init(1, 1, N);
	while (!v.empty()) {
		ll idx = v.back().second;
		v.pop_back();
		ans += query(1, 1, N, 1, idx);
		update(1, 1, N, idx);
	}
	cout << ans;
	return 0;
}
