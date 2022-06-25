#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	int sum = 0;

	cin >> n >> x;
	int* nums = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = 0; i < x; i++)
		sum += nums[i];
	int* sums = new int[n - x + 1];
	int j = 0;
	sums[j++] = sum;
	for (int i = x; i < n; i++)
	{
		sum += nums[i];
		sum -= nums[i - x];
		sums[j++] = sum;
	}

	sort(sums, sums + j);
	int count = 0;
	for (int i = j-1; i >= 0; i--)
	{
		if (sums[j - 1] > sums[i])
			break;
		else
			count++;
	}

	if (sums[j - 1] == 0)
		cout << "SAD";
	else
		cout << sums[j-1] << '\n' << count;

	return 0;
}
