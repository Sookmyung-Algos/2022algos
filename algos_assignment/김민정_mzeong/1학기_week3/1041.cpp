#include <iostream>
#include <algorithm>
using namespace std;

long long  n;
long long answer = 0;
int arr[6];
int max_num = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	cin >> n;
	for (int i = 0; i < 6; i++) {
			cin >> arr[i];
			answer += arr[i];
			max_num = max(max_num,arr[i]);
	}
	if (n == 1) cout << answer - max_num;
	else {
		answer = 0;
		arr[0] = min(arr[0], arr[5]);
		arr[1] = min(arr[1], arr[4]);
		arr[2] = min(arr[2], arr[3]);
	
		sort(arr, arr + 3);
		int sum1 = arr[0];
		int sum2 = sum1 + arr[1];
		int sum3 = sum2 + arr[2];

		answer += sum3 * 4;
		answer += sum2 * (4 * (n - 2) + 4 * (n - 1));
		answer += sum1 * (4 * (n - 1)*(n - 2) + (n - 2)*(n - 2));

		cout << answer;
	}
	return 0;
}
