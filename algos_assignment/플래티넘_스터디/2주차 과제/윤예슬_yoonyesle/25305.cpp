#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k, a[1001];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	printf("%d", a[n - k]);
	return 0;
}
