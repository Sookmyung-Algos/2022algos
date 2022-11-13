#include<iostream>
#include<vector>
using namespace std;

int N, M, sum = 0;
int memory[101], cost[101], dp[101][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
        sum += cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (cost[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
