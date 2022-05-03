#include <iostream>
#include <stack>
using namespace std;
int arr[10000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	
	int count = 0;

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < a; i++) {
		for (int j = i+1; j < a; j++) {
			if (arr[i] + arr[j] == b) count++;
		}
	}
	cout << count;

}
