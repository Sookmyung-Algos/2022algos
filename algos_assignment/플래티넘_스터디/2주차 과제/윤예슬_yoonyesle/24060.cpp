#include <iostream>
using namespace std;

int a[500'001], tmp[500'001], k, cnt;

void merge(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
	while (i <= q && j <= r) {
		if (a[i] <= a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++];
 	}
 	while (i <= q)
 		tmp[t++] = a[i++];
 	while (j <= r)
 		tmp[t++] = a[j++];
 	i = p; t = 1;
 	while (i <= r) {
 		a[i++] = tmp[t++];
 		if (++cnt == k) printf("%d", a[i - 1]);
 	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	merge_sort(0, n - 1);
	if (cnt < k) printf("-1");
	return 0;
}
