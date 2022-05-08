#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, m, N[100001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	int ans = 0, tmp = 0;
	for (int i = 1; i <= m; i++)
		tmp += N[i];
	ans = tmp;
	for (int i = m + 1; i <= n; i++) {
		tmp = tmp + N[i] - N[i - m];
		ans = max(ans, tmp);
	}
	cout << ans;
}
