#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> init(string s) {
	int patternSize = s.size();
	vector<int> v(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && s[i] != s[j]) j = v[j - 1];
		if (s[i] == s[j]) v[i] = ++j;
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		vector<int> v = init(s.substr(i, s.length()-i));
		for (int j = 0; j < s.size() - i; j++) {
			ans = max(ans, v[j]);
		}
	}

	cout << ans;

	return 0;
}
