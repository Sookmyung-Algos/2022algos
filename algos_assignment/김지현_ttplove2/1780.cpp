#include <iostream>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3] = { 0, };

bool isSame(int n, int x, int y) {
	bool flag = true;
	int start = paper[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (start != paper[i][j]) {
				flag = false;
			}
		}
	}
	if (flag == true) return true;
	else return false;
}

void solve(int n, int x, int y) {
	if (isSame(n, x, y)) {
		cnt[paper[x][y] + 1]++;
	}
	else {
		int newN = n / 3;
		for (int i = x; i < x + n; i += newN) {
			for (int j = y; j < y + n; j += newN) {
				solve(newN, i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	solve(N, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}
	return 0;
}
