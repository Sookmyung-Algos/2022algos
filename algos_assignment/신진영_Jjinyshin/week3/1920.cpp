//endl -> "\n"으로 바꿔주고 ios_base::sync_with_stdio(0);cin.tie(0); 추가해주니까 시간초과 해결

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];
void bi_search(int find) {
	int start = 0;
	int end = n - 1;
	int mid;

	while (end >= start) {
		mid = (start + end) / 2;
		if (arr[mid] == find) {
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] > find) {
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << 0 << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		bi_search(tmp);
	}
	return 0;
}
