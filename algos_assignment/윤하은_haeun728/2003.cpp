#include <iostream>
using namespace std;
long long arr[10000];
int num, tot;
long long result = 0;

void dp(int idx, long long sum) {
    if (idx == num)
        return;
    if (sum + arr[idx] == tot) {
        result++;
        return;
    }
    else if (sum + arr[idx] > tot)
        return;
    else if (sum + arr[idx] < tot)
        dp(idx + 1, sum + arr[idx]);
}

int main() {
    cin >> num >> tot;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    for (int i = 0; i < num; i++)
        dp(i, 0);
    cout << result;
    return 0;
}
