#include <iostream>
#include <string>
using namespace std;

int main() {

	string a, b;
	int minCnt = 50;

	cin >> a >> b;

	int lenA = a.length();
	int lenB = b.length();

	for (int i = 0; i < lenB - lenA + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < lenA; j++) {
			if (a[j] != b[i + j]) {
				cnt++;
			}
		}
		if (cnt < minCnt) {
			minCnt = cnt;
		}
	}

	cout << minCnt;

	return 0;
}
