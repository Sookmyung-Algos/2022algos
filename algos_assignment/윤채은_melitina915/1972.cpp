#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int i, j, k, w;

    while (cin >> s) {
        if (s == "*") {
            return 0;
        }

        bool check = true;
        for (i = 1; i < s.length() - 1; i++) {
            char a, b;
            for (j = 0; j < s.length() - i; j++) {
                a = s[j];
                b = s[j + i];
                if (j + i == s.length() - 1) {
                    continue;
                }
                for (int k = j + 1; k < s.length() - i; k++) {
                    if (a == s[k] && b == s[k + i]) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    break;
                }
            }
            if (!check) {
                break;
            }

        }
        for (int w = 0; w < s.length(); w++) {
            cout << s[w];
        }
        if (check) {
            cout << " is surprising." << endl;
        }
        if (!check) {
            cout << " is NOT surprising." << endl;
        }

    }
    return 0;
}
