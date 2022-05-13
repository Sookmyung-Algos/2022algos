#include <iostream>
#include <algorithm>
using namespace std;

int dis[100010];
int money[100010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	long long ans = 0;
	long long now_m;

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	now_m = money[0];
	ans = now_m * dis[0];

	for (int i = 1; i < N; i++) {
		if (now_m < money[i]) {
			ans += now_m * dis[i];
		}
		else {
			now_m = money[i];
			ans += now_m * dis[i];
		}
	}
	cout << ans;
	return 0;
}
