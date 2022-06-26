#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	int n;
	int m[100001];
	int Max = -1000;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		m[i] = m[i - 1] + n;
	}
	for (int i = M; i <= N; i++) {
		Max = max(Max, m[i] - m[i - M]);
	}
	cout << Max;
}
