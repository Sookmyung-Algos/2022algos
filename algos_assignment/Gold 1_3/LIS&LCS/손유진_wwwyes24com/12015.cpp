#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000010];
int index[1000010];

int main() {
	int n, ai, idx = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		if (idx == 0) {
			index[idx++] = ai;
		}
		else {
			if (index[idx - 1] < ai) 
				index[idx++] = ai;
			else  
				index[lower_bound(index, index + idx, ai) - index] = ai;
		}
	}
	cout << idx;
}
