#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	char tmp[55];
	cin.getline(tmp, 55);
	for (int i = 1; i <= n; ++i) {
		cin.getline(tmp, 55);
		cout << i << ". " << tmp << endl;
	}
	return 0;
}
