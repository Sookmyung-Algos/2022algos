#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1234567;
int button[4][3], dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
long long dp[10][1001], sum[1001];
vector<int> adj[10];

void init(void) {
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;

	int num = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			button[i][j] = num++;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				int ni = i + dir[k][0], nj = j + dir[k][1];
				if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
					adj[button[i][j]].push_back(button[ni][nj]);
			}
		}
	}

	adj[0].push_back(7);
	adj[7].push_back(0);

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (auto& k : adj[j]) {
				dp[k][i] += dp[j][i - 1];
				dp[k][i] %= MOD;
			}
		}
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			sum[i] += dp[j][i];
			sum[i] %= MOD;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}

	return 0;
}
