#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;
	vector<int> pos;
	vector<int> neg;
	int zero_c = 0;
	int one_c = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			one_c++;
		}
		else if (a == 0) {
			zero_c++;
		}
		else if (a > 0) {
			pos.push_back(a);
		}
		else {
			neg.push_back(a);
		}
	}

	sort(pos.begin(), pos.end(), greater<int>());  //내림차순
	sort(neg.begin(), neg.end());

	if (pos.size() % 2 == 1)
		pos.push_back(1); //계산 안터지게, 결과값은 안변함
	if (neg.size() % 2 == 1) {
		if (zero_c > 0) {
			neg.push_back(0);
		}
		else {
			neg.push_back(1);
		}
	}

	int ans = 0;
	for (int i = 0; i < pos.size(); i += 2) {
		ans += pos[i] * pos[i + 1];
	}
	for (int i = 0; i < neg.size(); i += 2) {
		ans += neg[i] * neg[i + 1];
	}
	ans = ans + one_c;
	cout << ans;
	return 0;
}
