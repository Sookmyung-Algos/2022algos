#include <iostream>

using namespace std;

int main() {
    int N, K, ans;
    int ice[1000001];

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int g, x;
        cin >> g >> x;
        ice[x] = g;
    }

    K = 2 * K + 1;
    int sum = 0;
    for (int i = 0; i <= 1000001; i++) {
        if (i >= K) {
            sum -= ice[i - K];
        }
        sum += ice[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
