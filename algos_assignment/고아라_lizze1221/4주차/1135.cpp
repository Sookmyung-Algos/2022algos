#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> child[50];
int tree_dp[50];

int DP(int cur) {
	if (tree_dp[cur] != - 1) return tree_dp[cur];
	if (!child[cur].size()) return tree_dp[cur] = 0;

    vector<int> cur_child_cost;
    
	for (int i = 0; i < child[cur].size(); i++) {
		cur_child_cost.push_back(DP(child[cur][i]));
	}
	sort(cur_child_cost.begin(), cur_child_cost.end(), greater<>());
	for (int i = 0; i < cur_child_cost.size(); i++) {
		cur_child_cost[i] += i + 1;
	}
    
	return tree_dp[cur] = *max_element(cur_child_cost.begin(), cur_child_cost.end());
}

int main() {
	ios::sync_with_stdio(0);
    cout.tie(0);
    
	int tmp;
	cin >> n;
	cin >> tmp;
	for (int i = 1; i < n; i++)
		cin >> tmp, child[tmp].push_back(i);

	for (int i = 0; i < n; i++)
		tree_dp[i] = -1;

	cout << DP(0);

	return 0;
}
