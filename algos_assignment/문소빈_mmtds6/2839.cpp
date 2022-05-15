#include <iostream>
using namespace std;

int main() {

	int N, m, cnt, mod;

	cin >> N;

	m = N / 5;

	while (m >= 0) {
		mod = 0;
		cnt = 0;
		if (m > 0) {
			mod = N - 5 * m;
			cnt = m;
		}
		else {
			mod = N;
		}
		cnt += mod / 3;
		mod = mod % 3;
		if (mod == 0) {
			cout << cnt;
			break;
		}
		m--;
	}
	if (mod != 0) {
		cout << -1;
	}


	return 0;
}
