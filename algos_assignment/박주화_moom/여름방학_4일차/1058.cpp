#include <iostream>
#include <vector>
using namespace std;

int N, visit[50], num, max_n = 0;
vector <int> f[50];

void dfs(int now, int level)
{
	visit[now] = 1;
	if (level == 2)
		return;
	for (int i = 0; i < f[now].size(); i++)
	{
		int next = f[now][i];
		if (!visit[next])
			num++;
		dfs(next, level+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	char c;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			if (c == 'Y')
				f[i].push_back(j);
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visit[j] = 0;
		num = 0;
		dfs(i, 0);
		max_n = max(max_n, num);
	}

	cout << max_n;
	return 0;
}
