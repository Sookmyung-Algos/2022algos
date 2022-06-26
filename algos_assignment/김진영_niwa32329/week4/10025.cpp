#include <iostream>

using namespace std;

int n, k, ans;
int arr[1000001];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }

    k = 2 * k + 1;
    int sum = 0;
    for (int i = 0; i <= 1000001; i++) {
        if (i >= k) {
            sum -= arr[i - k];
        }
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
