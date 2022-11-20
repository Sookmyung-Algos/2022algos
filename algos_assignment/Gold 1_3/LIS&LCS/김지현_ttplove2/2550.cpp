#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 987564321
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<int> switchNum(N + 1);
	vector<int> sidx(N + 1);
	vector<int> bulbNum(N + 1);
	vector<int> bidx(N + 1);
	vector<int> lis(N, MAX);
	vector<pair<int, int>> trace;
	vector<int> ansIdx, ans;

	for (int i = 0; i < N; i++) {
		cin >> switchNum[i];
		sidx[switchNum[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> bulbNum[i];
		bidx[i] = sidx[bulbNum[i]];
	}

	int maxN = 0;
	int lisSize = 0;
	lis[0] = bidx[0];
	trace.push_back({ 0, bidx[0] });

	for (int i = 1; i < N; i++)
	{
		auto it = lower_bound(lis.begin(), lis.end(), bidx[i]) - lis.begin();
		lis[it] = bidx[i];
		trace.push_back({ it, bidx[i] });
	}

	int len = lis.size();
	for (int i = 0; i < len; i++)
		if (lis[i] != MAX)
			lisSize++;

	lisSize--;
	len = trace.size();
	for (int i = len - 1; i >= 0; i--)
	{
		if (trace[i].first != lisSize)
			continue;

		ansIdx.push_back(trace[i].second);   
		lisSize--;
	}

	len = ansIdx.size();
	for (int i = 0; i < len; i++)
		ans.push_back(switchNum[ansIdx[i]]);

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}
