#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000];
int sum[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i + n] = arr[i];
    }

    sum[1] = arr[1];

    for (int i = 2; i <= 2*n; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = k; i <= 2 * n; i++) {
        ans = max(ans, sum[i]-sum[i-k]);
    }

    cout << ans;

}
