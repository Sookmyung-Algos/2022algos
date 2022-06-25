#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int N, B, K;
	bool map[100001];
	int now;
	int ans = 100000;

	memset(map, false, sizeof(map));

	cin >> N >> K >> B;

	for (int i = 1; i <= B; i++)
	{
		cin >> now;
		map[now] = true;
	}
	int count = 0;

	for (int i = 1; i <= K; i++)
		count += map[i];
	ans = count;

	int j = 1;
	for (int i = K + 1; i <= N; i++)
	{
		count += map[i];
		count -= map[j++];
		ans = min(ans, count);
	}

	cout << ans << '\n';
}
