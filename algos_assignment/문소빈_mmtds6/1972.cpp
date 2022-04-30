#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	while (1) {
		string s;
		cin >> s;

		if (s == "*") {
			break;
		}

		int sLen = s.length();
		int d = 1;
		bool surprising = true;

		while (d < sLen) {
			vector <string> v;
			for (int i = 0; i <= sLen - d; i++) {
				string tmp = "";
				tmp += s[i];
				tmp += s[i + d];
				v.push_back(tmp);
			}

			for (int i = 0; i < v.size(); i++) {
				for (int j = i + 1; j < v.size(); j++) {
					if (v[i] == v[j]) {
						surprising = false;
						break;
					}
				}
			}

			if (!surprising) {
				break;
			}
			d++;
		}

		if (surprising) {
			cout << s << " is surprising." << endl;
		}
		else {
			cout << s << " is NOT surprising." << endl;
		}

	}

	return 0;
}
