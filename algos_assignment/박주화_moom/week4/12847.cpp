#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	long long w = 0, *ww;

	cin >> n >> m;
	long long* wage = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> wage[i];

	for (int i = 0; i < m; i++)
		w += wage[i];
	ww = new long long[n - m + 1];
	int j = 0;
	ww[j++] = w;

	for (int i = m; i < n; i++)
	{
		w += wage[i];
		w -= wage[i - m];
		ww[j++] = w;
	}

	sort(ww, ww + j);
	cout << ww[j-1];
	return 0;
}
