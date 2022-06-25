#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	int sum = 0;

	cin >> n >> k;
	int* nums = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = 0; i < k; i++)
		sum += nums[i];
	int* sums = new int[n];
	int j = 0;
	sums[j++] = sum;
	for (int i = k; (i-k) < (n-1); i++)
	{
		sum -= nums[i-k];
		sum += nums[i%n];
		sums[j++] = sum;
	}

	sort(sums, sums+j);
	cout << sums[j-1];

	return 0;
}
