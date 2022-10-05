#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd (ll a, ll b)
{
    ll ret = a % b;
    while (ret != 0)
    {
        a = b;
        b = ret;
        ret = a % b;
    }
    return b;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans;
        while (true)
        {
            if (b % a == 0)
            {
                ans = b / a;
                break;
            }
            ans = b / a + 1;
            a = a * ans - b;
            b = b * ans;
            int factor = gcd (b, a);
            a /= factor;
            b /= factor;
        }
        cout << ans << "\n";
    }
    return 0;
}
