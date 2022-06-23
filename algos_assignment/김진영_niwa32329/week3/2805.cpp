#include <iostream>
#include <algorithm>
using namespace std; 

int n, m, num[1000001] = { 0, };


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i]; 
	}
	
	sort(num, num + n); 
	int res;
	int start = 0;
	int end = num[n-1]; 

	while (start <= end) {
		long long sum = 0; 
		int mid = (start + end) / 2; 

		for (int i = 0; i < n; i++) {
			if (num[i] > mid) sum += num[i] - mid; 
		}
		if (sum < m) end = mid - 1;
		else {
			res = mid;
			start = mid + 1; 
		}
	}
	cout << res; 

	return 0; 
}
