#include <iostream>
#include <algorithm>
using namespace std; 

int n, m, a[100001] = { 0, };

int search(int a[], int num) {
	int start = 0;
	int end = n - 1; 
	int mid; 

	while (start <= end) {
		mid = (start + end) / 2; 
		if (a[mid] == num) {
			cout << '1' << '\n';
			return 1; 
		}
		if (num < a[mid]) end = mid - 1;
		else if (num > a[mid]) start = mid + 1; 
	}
	cout << '0' << '\n'; 
	return 0 ; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	sort(a, a + n); 
	cin >> m; 
	for (int i = 0; i < m; i++) {
		int b; 
		cin >> b; 
		search(a,b); 
	}
	return 0; 
}
