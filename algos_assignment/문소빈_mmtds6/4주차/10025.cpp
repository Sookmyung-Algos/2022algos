#include <iostream>

using namespace std;

int N, K, ans;
int arr[1000001];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }

    K = 2 * K + 1;
    int sum = 0;
    for (int i = 0; i <= 1000001; i++) {
        if (i >= K) {
            sum -= arr[i - K];
        }
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
