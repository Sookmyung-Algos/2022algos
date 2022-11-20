#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int dp[101][101][101];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> s1 >> s2 >> s3;
    int i, j, k;
    for (i = 1; i <= s1.length(); i++) {
        for (j = 1; j <= s2.length(); j++) {
            for (k = 1; k <= s3.length(); k++) {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    cout << dp[i-1][j-1][k-1];
    return 0;
}
