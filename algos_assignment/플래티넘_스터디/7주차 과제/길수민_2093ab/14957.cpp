#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 5 * 1e4 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, m;
int l_val[MAX];
int u_val[MAX];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n >> m;
    vector<int> l_x (n), l_y(n + 1), u_x(m), u_y(m + 1);
    for (int i = 0; i < 2 * n + 1; i++)
    {
        if (i & 1) cin >> l_x[i / 2];
        else cin >> l_y[i / 2];
    }
    for (int i = 0; i < 2 * m + 1; i++)
    {
        if (i & 1) cin >> u_x[i / 2];
        else cin >> u_y[i / 2];
    }
    int cur_l = 0, cur_u = 0;
    ll ans = 0;
    bool s_flag = l_y[0] > u_y[0];
    int cnt = 0;
    bool flag = l_y[0] < u_y[0];
    for (int i = 0; i < 50003; i++)
    {
        l_val[i] = l_y[cur_l];
        u_val[i] = u_y[cur_u];

        if (cur_l < n && l_x[cur_l] == i) cur_l++;
        if (cur_u < m && u_x[cur_u] == i) cur_u++;
        if (s_flag && u_val[i] > l_val[i]) ans += u_val[i] - l_val[i];
        if (!flag && u_val[i] > l_val[i]) flag = true;
        if (flag && u_val[i] < l_val[i]) {
            flag = false;
            if (s_flag) cnt++;
        }
        if (!s_flag && l_val[i] > u_val[i]) s_flag = true;
    }
    if (s_flag && u_y[m] > l_y[n]) {
        for (int i = 50002; i >= 0; i--)
        {
            if (u_val[i] < l_val[i]) break;
            ans -= u_val[i] - l_val[i];
        }
    }
    cout << cnt << " " << ans << "\n";

    return 0;
}
