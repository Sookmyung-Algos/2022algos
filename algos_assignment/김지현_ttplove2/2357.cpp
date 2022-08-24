#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define MAXN 100001
using namespace std;

int N, M;
int num[MAXN];
vector<int> min_tree, max_tree;

void init(int node, int s, int e) {
	if (s == e) {
		min_tree[node] = max_tree[node] = num[s];
		return;
	}
	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
		return;
	}
}

pair<int, int> findMinMAx(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return make_pair(INT32_MAX, 0);
	}
	else if (l <= s && e <= r) {
		return make_pair(min_tree[node], max_tree[node]);
	}
	else {
		pair<int, int> left, right;
		left = findMinMAx(node * 2, s, (s + e) / 2, l, r);
		right = findMinMAx(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
		return make_pair(min(left.first, right.first), max(left.second, right.second));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> num[i];

	// https://hddcp.tistory.com/31 글 참조
	int h = 1 << int(ceil(log2(N)) + 1);
	min_tree.resize(h);
	max_tree.resize(h);

	init(1, 1, N);
	pair<int, int> result;
	while (M--) {
		int l, r;
		cin >> l >> r;
		result = findMinMAx(1, 1, N, l, r);
		cout << result.first << " " << result.second << "\n";
	}
	return 0;
}
