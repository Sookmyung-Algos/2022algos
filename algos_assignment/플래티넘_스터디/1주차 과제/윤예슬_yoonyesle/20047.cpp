#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    string s, t;
    cin >> n >> s >> t >> i >> j;
    char first = s[i], second = s[j];
    s = s.substr(0, i) + s.substr(i + 1, j - i - 1) + s.substr(j + 1, n - j - 1);
    bool dp[10'001][3];
    dp[0][0] = t[0] == s[0];
    dp[0][1] = t[0] == first;
    dp[0][2] = false;
    for (int i = 1; i < t.length(); ++i) {
        dp[i][0] = dp[i - 1][0] && (t[i] == s[i]);
        dp[i][1] = (dp[i - 1][0] && (t[i] == first)) || (dp[i - 1][1] && (t[i] == s[i - 1]));
        dp[i][2] = (dp[i - 1][1] && (t[i] == second)) || (dp[i - 1][2] && (t[i] == s[i - 2]));
    }
    if (dp[n - 1][2])
        cout << "YES";
    else
        cout << "NO";
}
