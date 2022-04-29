#include <iostream>
using namespace std;

int N;
int wine[10001];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1];
	if (N > 1) dp[2] = wine[1] + wine[2];
	if (N > 2) {
		for (int i = 3; i < N + 1; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + wine[i]);
			dp[i] = max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
