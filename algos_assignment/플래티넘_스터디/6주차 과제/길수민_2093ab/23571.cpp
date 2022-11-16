#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int front_dp[MAX][2];
int end_dp[MAX][2];
int price[MAX];
int value[MAX];
int cur = 0;
int cur_val = 0;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> value[i];
    sort (price, price + n);
    sort (value, value + n);
    for (int i = 0; i < n; i++){
        front_dp[i][0] = -1;
        front_dp[i][1] = MOD;
        end_dp[i][0] = -1;
        end_dp[i][1] = MOD;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0) front_dp[i][0] = abs(price[i] - value[i]);
        else front_dp[i][0] = max (front_dp[i - 1][0], abs (price[i] - value[i]));
        front_dp[i][1] = front_dp[i][0];
        if (i == 0) front_dp[i][1] = min (front_dp[i][1], abs (price[i] - value[i + 1]));
        else {
            front_dp[i][1] = min (front_dp[i][1], \
                    max (front_dp[i - 1][1], abs (price[i] - value[i + 1])));
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (i == n - 1) end_dp[i][0] = abs (price[i] - value[i]);
        else end_dp[i][0] = max (end_dp[i + 1][0], abs (price[i] - value[i]));
        end_dp[i][1] = end_dp[i][0];
        if (i == n - 1) end_dp[i][1] = min (end_dp[i][1], abs (price[i] - value[i - 1]));
        else {
            end_dp[i][1] = min (end_dp[i][1], \
                    max (end_dp[i + 1][1], abs (price[i] - value[i - 1])));
        }
    }
    cur = 0;
    cur_val = end_dp[1][1];
    for (int i = 1; i < n - 1; i++)
    {
        int ret1 = front_dp[i - 1][0];
        ret1 = max (ret1, end_dp[i + 1][1]);
        int ret2 = front_dp[i - 1][1];
        ret2 = max (ret2, end_dp[i + 1][0]);
        if (ret1 < cur_val) {
            cur = i;
            cur_val = ret1;
        }
        if (ret2 < cur_val) {
            cur = i;
            cur_val = ret2;
        }
    }
    if (front_dp[n - 2][1] < cur_val) cur = n - 1;
    cout << price[cur] << "\n";
    return 0;
}

