#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(int idx, int weight);

int N, K, tmp;
bool dp[32][15002];
int W[102];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	solve(0, 0);
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		if (tmp > 15000) cout << "N ";
		else if (dp[N][tmp]) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}

void solve(int idx, int weight) {
	if (idx > N || dp[idx][weight]) return;
	dp[idx][weight] = true;
	solve(idx + 1, weight);
	solve(idx + 1, weight + W[idx]);
	solve(idx + 1, abs(weight - W[idx]));
}