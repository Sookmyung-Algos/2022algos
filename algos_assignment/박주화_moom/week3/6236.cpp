#include <iostream>
using namespace std;

int n, m, sum = 0, mk = 0;

int cnt(int* money, int k)
{
	int c = 1, kk = k;

	for (int i = 0; i < n; i++)
	{
		if (kk < money[i])
		{
			c++;
			kk = k;
		}
		kk -= money[i];
	}
	return c;
}
int find(int* money, int m)
{
	int start = mk, end = sum, mid, k = end;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int c = cnt(money, mid);
		if (m >= c)
		{
			k = mid;
			end = mid - 1;
		}
		else if (m < c)
			start = mid + 1;
	}
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int* money;

	cin >> n >> m;
	money = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
		sum += money[i];
		mk = max(mk, money[i]);
	}

	cout << find(money, m);
	return 0;
}
