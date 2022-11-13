#include<iostream>
#include<vector>
#define INF 1e18
using namespace std;

int N, M;
vector<pair<long long, long long>> v;
long long dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	cin >> M;
	if (M == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < 100001; i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = M - (v[i].first - 2); j >= 1; j--) {
			if (dp[j] == INF) continue;
			dp[j + (v[i].first - 2)] = min(dp[j + (v[i].first - 2)], dp[j] + v[i].second);
		}
		if (v[i].first - 1 <= M) {
			dp[v[i].first - 1] = min(dp[v[i].first - 1], v[i].second);
		}
	}

	if (dp[M] == INF) cout << -1;
	else cout << dp[M];

	return 0;
}
