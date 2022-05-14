#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> time;
	int N = 0;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		time.push_back(k);
	sort(time.begin(), time.end());

	for (int i = 0; i < N; i++) {
		sum += time[i] * (N - i);
	}
	cout << sum;

	return 0;
}
