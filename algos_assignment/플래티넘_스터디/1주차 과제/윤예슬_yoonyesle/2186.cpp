#include <iostream>

using namespace std;

string match;
string board[101];
int dp[101][101][81], n, m, k;
pair<int,int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int f(int i, int j, int d) {
    if (i >= n || j >= m || i < 0 || j < 0)
        return 0;
    if (dp[i][j][d] >= 0)
        return dp[i][j][d];
    if (board[i][j] != match[d])
        return 0;
    if (d == match.length() - 1)
        return 1;
    int ret = 0;
    for (int dir_idx = 0; dir_idx < 4; ++dir_idx)
        for (int qq = 1; qq <= k; ++qq)
            ret += f(i + dir[dir_idx].first * qq, j + dir[dir_idx].second * qq, d + 1);
    return dp[i][j][d] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cin >> match;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int q = 0; q <= match.length(); ++q)
                dp[i][j][q] = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += f(i, j, 0);
    cout << ans;
}
