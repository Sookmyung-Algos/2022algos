#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, pi> pipi;

int N, M, K;
int dp[1001][1001];
pi cost[1001][1001];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 1 && b == 1)
            dp[0][0] += 1;
        else
        {
            if (b != 1) {
                for (int j = a; j <= c; j++)
                    cost[j - 1][b - 2].first++;
            }
            if (a != 1) {
                for (int j = b; j <= d; j++)
                    cost[a - 2][j - 1].second++;
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
        dp[i + 1][0] = dp[i][0] + cost[i][0].second;
    for (int i = 0; i < M - 1; i++)
        dp[0][i + 1] = dp[0][i] + cost[0][i].first;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
            dp[i][j] = min (dp[i - 1][j]+cost[i - 1][j].second,\
                    dp[i][j - 1]+cost[i][j - 1].first);
    }
    cout << dp[N - 1][M - 1] << "\n";
    return 0;
}
