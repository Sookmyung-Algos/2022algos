#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int c;

	cin >> c;

	while (c--) {
		int n, m;
		int ans = 0;
		pair<int, int> arr[1000];
		bool check[1001] = {};

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> arr[i].second >> arr[i].first;
		}

		sort(arr, arr + m);

		for (int i = 0; i < m; i++) {
			for (int j = arr[i].second; j <= arr[i].first; j++) {
				if (!check[j]) {
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (check[i])
				ans++;

		cout << ans << endl;
	}

}
