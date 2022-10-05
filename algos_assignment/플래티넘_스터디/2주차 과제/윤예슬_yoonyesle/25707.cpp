#include <stdio.h>
#include <algorithm>
using  namespace std;

int main() {
    int n, a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    sort(a, a + n);
    printf("%d", 2 * (a[n - 1] - a[0]));
}
