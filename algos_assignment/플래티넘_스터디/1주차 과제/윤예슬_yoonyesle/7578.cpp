#include <iostream>
#include <map>
using namespace std;

long long tree[500'001 << 2];

void update(int node, int start, int end, int i) {
	if (i < start || end < i) return;
	if (start == end) {
		++tree[node];
		return;
	}
	update(node * 2, start, (start + end) / 2, i);
	update(node * 2 + 1, (start + end) / 2 + 1, end, i);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int i, int j) {
	if (j < start || end < i) return 0;
	if (i <= start && end <= j) return tree[node];
	return query(node * 2, start, (start + end) / 2, i, j)
		+ query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	int n, a[500'001];
	map<int, int> b;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		int num;
		scanf("%d", &num);
		b.insert({num, i});
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += query(1, 1, n, b.find(a[i])->second + 1, n);
		update(1, 1, n, b.find(a[i])->second);
	}
	printf("%lld", ans);
	return 0;
}
