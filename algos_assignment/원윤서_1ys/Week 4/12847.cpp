#include <iostream>

using namespace std;

int main() {
    int n, m;
    int pay[100001];
    long long sum1 = 0;

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        cin >> pay[i];
    }

    long long sum2 = 0;

    for (int i = 0; i <= n; i++) {
        if (i > m) {
            sum2 -= pay[i - m];
        }
        sum2 += pay[i];
        sum1 = max(sum1, sum2);
    }
    cout << sum1;

    return 0;
}
