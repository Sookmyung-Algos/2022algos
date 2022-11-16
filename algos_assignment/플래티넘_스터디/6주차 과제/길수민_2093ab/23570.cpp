#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e7 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
ll ans, a, b, c;

ll calc (ll n)
{
    ll ret = 0;
    if (n <= 0) return 0;
    ll first = (n + 1) / 2;
    ll second = n / 2;
    ret += first * (first + 1) / 2;
    ret += second * (second + 1) / 2;
    return ret;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> a >> b >> c;
    if (a > b) swap (a, b);
    if (b > c) swap (b, c);
    if (a > b) swap (a, b);
    ans += 48 * calc (a - 2);
    ans += 16 * (calc (a - 1) - calc (2 * a - 1 - b));
    cout << ans << "\n";
    return 0;
}
