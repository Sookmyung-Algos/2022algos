#include <iostream>
using namespace std;

int dnaCount(char c) {
	if (c == 'A') {
		return 0;
	}
	else if (c == 'C') {
		return 1;
	}
	else if (c == 'G') {
		return 2;
	}
	else if (c == 'T') {
		return 3;
	}
}

char dna[1000001] = { 0, }, pw[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int s, p, a, c, g, t, dnaCheck[4] = { 0, }, cnt = 0;

	cin >> s >> p;

	for (int i = 0; i < s; i++) {
		cin >> dna[i];
	}

	cin >> a >> c >> g >> t;

	for (int i = 0; i < p; i++) {
		dnaCheck[dnaCount(dna[i])]++;
	}


	for (int i = 0; i < s - p + 1;) {
		if (dnaCheck[0] >= a && dnaCheck[1] >= c && dnaCheck[2] >= g && dnaCheck[3] >= t) {
			cnt++;
		}
		dnaCheck[dnaCount(dna[i])]--;
		i++;
		dnaCheck[dnaCount(dna[i + p - 1])]++;

	}

	cout << cnt;

	return 0;
}
