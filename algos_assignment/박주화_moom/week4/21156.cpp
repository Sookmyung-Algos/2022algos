#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int team[101], rank[101];
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		team[i] = i;
		rank[i] = i;
	}
	int a, b;
	char c, d;
	for (int i = 0; i < m; i++)
	{
		cin >> c >> a >> d >> b;
		if (rank[a] > rank[b])
		{
			for (int j = rank[b]; j < rank[a]; j++)
			{
				team[j] = team[j + 1];
				rank[team[j]]--;
			}
			team[rank[a]+1] = b;
			rank[b] = rank[a] + 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << 'T' << team[i] << ' ';
	}
	return 0;
}
