#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> rion_position;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int now;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> now;
		if (now == 1)
			rion_position.push_back(i);
	}

	int ans = 1000001;

	if (rion_position.size() < K)
	{
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i <= rion_position.size() - K; i++)
	{
		ans = min(ans, rion_position[i + K - 1] - rion_position[i] + 1);
	}

	cout << ans << '\n';
}