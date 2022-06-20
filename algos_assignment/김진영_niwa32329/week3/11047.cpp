#include <iostream>

using namespace std; 

int n, k,res=0; 
int num[10] = { 0, }; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		cin >> num[i]; 
	}
	int temp = k; 
	for (int i = n-1; i >= 0; i--) {
		if (num[i] <= temp) {
			while (1) { 
				temp -= num[i];
				res++; 
				if (temp - num[i] < 0) break; 
			}
		}
	}
	cout << res;

	return 0; 
}
