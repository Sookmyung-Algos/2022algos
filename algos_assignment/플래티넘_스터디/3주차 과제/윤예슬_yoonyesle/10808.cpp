#include <iostream>
using namespace std;

int main() {
	int ans[30] = {0};
	string s;
	cin >> s;
	for (auto i: s)
		++ans[i - 'a'];
	for (int i = 0; i < 26; ++i)
		cout << ans[i] << " ";
	return 0;
}
