#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int arr[44];
int N, S;
vector<int> l_ret;
vector<int> r_ret;

void backtrack (int step, int max_step, int sum, bool is_left)
{
    if (step == max_step) {
        if (is_left) l_ret.push_back (sum);
        else r_ret.push_back (sum);
        return;
    }
    backtrack (step + 1, max_step, sum, is_left);
    backtrack (step + 1, max_step, sum + arr[step], is_left);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int mid = N / 2;
    backtrack (0, mid, 0, true);
    backtrack (mid, N, 0, false);
    ll ans = 0;
    sort (r_ret.begin(), r_ret.end());
    for (auto& it : l_ret)
    {
        ans += distance (lower_bound (r_ret.begin(), r_ret.end(), S - it),\
                upper_bound (r_ret.begin(), r_ret.end(), S - it));
    }
    if (S == 0) cout << ans - 1 << "\n";
    else cout << ans << "\n";
    return 0;
}
