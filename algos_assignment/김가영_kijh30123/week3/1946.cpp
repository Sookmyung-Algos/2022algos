#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T,N;

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		
		sort(arr, arr + N);

		int ans = 0;
		int rank_1 = arr[0].second;
		
		for (int i = 1; i < N; i++) {
			if (arr[i].second < rank_1) {
				ans++;
				rank_1 = arr[i].second;
			}
		}
		cout << ans+1 << '\n'; //구한 값에서 최초 합격자 더한다
	}
	return 0;
}
