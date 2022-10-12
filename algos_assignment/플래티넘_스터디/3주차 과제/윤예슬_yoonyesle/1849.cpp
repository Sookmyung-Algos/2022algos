#include <iostream>
using namespace std;

#define MAX 1000001

int arr[MAX], tree[MAX << 2];

int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = 1;
	return tree[node] = init(node * 2, start, (start + end) / 2)
		+ init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int i) {
	if (i < start || end < i) return;
	if (start == end) {
		tree[node] = 0;
		return;
	}
	update(node * 2, start, (start + end) / 2, i);
	update(node * 2 + 1, (start + end) / 2 + 1, end, i);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int i) {
	if (start == end) return start;
	if (i < tree[node * 2]) return query(node * 2, start, (start + end) / 2, i);
	return query(node * 2 + 1, (start + end) / 2 + 1, end, i - tree[node * 2]);
}

int main() {
	int n, ans[MAX + 1];
	scanf("%d", &n);
	init(1, 1, n);
    for(int i = 1; i <= n; ++i) {
    	int tmp;
        scanf("%d", &tmp);
        int idx = query(1, 1, n, tmp);
        ans[idx] = i;
        update(1, 1, n, idx);
    }
    for(int i = 1; i <= n; ++i)
    	printf("%d\n", ans[i]);
	return 0;
}
