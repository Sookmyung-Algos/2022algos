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
string str;
int dp[MAX];
int r = -1, j = -1;
string even_str;
int ans = 1;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> str;
    even_str.push_back ('#');
    for (auto& ch : str) {
        even_str.push_back (ch);
        even_str.push_back ('#');
    }
    int n = even_str.length();
    for (int i = 0; i < n; i++)
    {
        if (r < i) dp[i] = 0;
        else {
            int i_prime = 2 * j - i;
            dp[i] = min (r - i, dp[i_prime]);
        }
        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n\
                && even_str[i - dp[i] - 1] == even_str[i + dp[i] + 1])
            dp[i]++;
        if (dp[i] + i > r) {
            r = dp[i] + i;
            j = i;
        }
        ans = max (ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
