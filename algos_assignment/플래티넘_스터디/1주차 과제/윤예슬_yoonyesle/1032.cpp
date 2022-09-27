#include <iostream>
using namespace std;

int main() {
	int n;
	string fileName;
	scanf("%d", &n);
	--n;
	cin >> fileName;
	while (n--)  {
		string tmp;
		cin >> tmp;
		for (int i = 0; i < fileName.length(); ++i)
			if (fileName[i] != tmp[i])
				fileName[i] = '?';
	}
	cout << fileName;
	return 0;
}
