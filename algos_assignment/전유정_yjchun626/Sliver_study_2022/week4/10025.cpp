#include <iostream>

using namespace std;
const int MAX = 1000001;

int n, k, ans;
int arr[MAX];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }

    k = 2 * k + 1;
    int sum = 0;
    for (int i = 0; i <= MAX; i++) {
        if (i >= k) {
            sum -= arr[i - k];
        }
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
