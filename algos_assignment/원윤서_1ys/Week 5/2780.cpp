#include <iostream>
using namespace std;

int T, N;
int dp[1001][10];

void func() {
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j <= 9; j++) {
            switch (j) {
            case 0:
                dp[i][j] = dp[i - 1][7];
                break;
            case 1:
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
                break;
            case 2:
                dp[i][j] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
                break;
            case 3:
                dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
                break;
            case 4:
                dp[i][j] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
                break;
            case 5:
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8];
                break;
            case 6:
                dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
                break;
            case 7:
                dp[i][j] = dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0];
                break;
            case 8:
                dp[i][j] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
                break;
            case 9:
                dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
                break;
            }
            dp[i][j] = dp[i][j] % 1234567;
        }
    }
}

int main() {
    cin >> T;
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    func();

    while (T--) {
        int ans = 0;
        cin >> N;
        for (int i = 0; i < 10; i++) {
            ans += dp[N][i];
        }
        cout << ans % 1234567 << '\n';
    }
    return 0;
}

//참고: https://peanut2016.tistory.com/287
