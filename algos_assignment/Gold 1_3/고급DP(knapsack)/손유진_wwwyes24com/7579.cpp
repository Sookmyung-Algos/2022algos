#include <iostream>
using namespace std;
int v[110], w[110], dp[110][10010];
int n, m, sum = 0;
int main() {


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		sum += w[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}

}
