#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> array(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		cin >> array[i][0];
		cin >> array[i][1];
	}
	sort(array.begin(), array.end());
	for (int i = 0; i < array.size(); i++) {
		cout << array[i][0] << " " << array[i][1] << endl;
	}
}
