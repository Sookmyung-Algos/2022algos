#include <iostream>
#include <vector>

using namespace std;

long long sum[250001];

int main() {
    int n, x, num;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &num);
        if (i == 0) {
            sum[i] = num;
            continue;
        }
        sum[i] = sum[i - 1] + num;
    }

    int count = 1;
    long long maxSum = sum[x - 1];

    for (int i = x; i < n; i++) {
        if (maxSum < sum[i] - sum[i - x]) {
            maxSum = sum[i] - sum[i - x];
            count = 1;
        }
        else if (maxSum == sum[i] - sum[i - x]) {
            count += 1;
        }
    }
    if (maxSum == 0) {
        printf("SAD");
    }
    else {
        printf("%lld\n", maxSum);
        printf("%d", count);
    }
    return 0;
}
