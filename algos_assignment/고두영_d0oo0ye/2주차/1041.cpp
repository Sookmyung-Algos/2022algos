#include <iostream>
#include <algorithm>
using namespace std;

int arr[6] ;
int cube[3];
long long n;
long long ans = 0;

void solve() {
	cube[0] = min(arr[0], arr[5]);
    
	if (n == 1) {
		sort(arr, arr + 6);
		ans = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
	}
    
	else {
		cube[1] = min(arr[2], arr[3]);
		cube[2] = min(arr[1], arr[4]);
		sort(cube,cube+3);
        
		ans += cube[0] * (5 * n * n - 8 * n + 4);
		ans += cube[1] * (8 * n - 8);
		ans += 4 * cube[2];
	}
    
	cout << ans;
}

int main() {
	cin >> n;
    
	for (int i = 0; i < 6; i++) {
		int t;
		cin >> t;
		arr[i] = t;
	}
    
	solve();
	return 0;
}
