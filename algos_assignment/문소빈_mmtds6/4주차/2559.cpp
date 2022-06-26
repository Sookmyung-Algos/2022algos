#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

int Max(int a, int b) {
    return a > b ? a : b;
}

int arr[100001];

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int start = 0;
    int sum = 0;
    int maxSum = -1e9;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];

        if (i >= m - 1) {
            maxSum = Max(maxSum, sum);
            sum -= arr[start++];
        }
    }

    cout << maxSum;

    return 0;
}
