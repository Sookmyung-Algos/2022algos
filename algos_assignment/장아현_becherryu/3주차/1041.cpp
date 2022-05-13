#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long N;
	long long ans = 0;
	int dice[6];
	int maxn = 0;

	cin >> N;

	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		ans += dice[i];
		maxn = max(maxn, dice[i]);
	}

	if (N == 1)
		cout << ans - maxn; // 주사위의 최대값 빼고 다 더하기

	else {
		ans = 0;
		dice[0] = min(dice[0], dice[5]);
		dice[1] = min(dice[1], dice[4]);
		dice[2] = min(dice[2], dice[3]);

		sort(dice, dice + 3);
		int s1 = dice[0];
		int s2 = s1 + dice[1];
		int s3 = s2 + dice[2];

		ans += s1 * (4 * (N - 1) * (N - 2) + (N - 2) * (N - 2));
		ans += s2 * (4 * (N - 2) + 4 * (N - 1));
		ans += s3 * 4 ;

		cout << ans;
	}
	return 0;
}
