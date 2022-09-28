#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr.begin(), arr.end());
    ll ans = 0;
    vector<ll> prefix_sum(N);
    ll cur = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (i == 0) prefix_sum[i] = arr[N - 1] - arr[0];
        else prefix_sum[i] = prefix_sum[i - 1] + arr[N - 1 - i] - arr[i] + 3 * MOD;
        prefix_sum[i] %= MOD;
        ans += (prefix_sum[i] * cur) % MOD;
        ans %= MOD;
        cur *= 2;
        cur %= MOD;
    }

    cout << ans << "\n";
    return 0;
}
