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

bool KMP(string s1, string s2, vector<int> v) {
	int parentSize = s1.size();
	int patternSize = s2.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && s1[i] != s2[j]) j = v[j - 1];
		if (s1[i] == s2[j]) {
			if (j == patternSize - 1) return true;
			else j++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	vector<int> v = init(c);
	if (KMP(a, c, v) && KMP(b, c, v)) cout << "YES";
	else cout << "NO";

	return 0;
}
