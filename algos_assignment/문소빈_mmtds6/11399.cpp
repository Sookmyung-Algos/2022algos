#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int n, p, time = 0;
	vector <int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			time += v[j];
		}
	}

	cout << time << endl;
	return 0;

}

