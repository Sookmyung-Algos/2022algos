#include <bits/stdc++.h>
using namespace std;

int m[101], c[101], dp[10001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    int total = 0;
    for (int i = 1; i <= N; i++) cin >> m[i];
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        total += c[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = total; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j-c[i]]+m[i]);
        }
    }
    int i = 0;
    while (dp[i] < M) i++;
    cout << i;
    return 0;
}
