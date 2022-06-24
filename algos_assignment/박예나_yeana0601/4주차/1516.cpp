#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct MyStruct
{
	int time;
	vector <int> prefer;

}val;
val arr[501];
int n;
int dp[501];

int solved(int num) {
	if (dp[num] != 0) return dp[num];
	int maxed = 0;
	for (int i = 0; i < arr[num].prefer.size(); i++) {
		maxed = max(maxed, solved(arr[num].prefer[i]));
	}
	dp[num] = maxed + arr[num].time;
	return dp[num];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].time;
		int temp;
		while (1) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			arr[i].prefer.push_back(temp);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << solved(i) << "\n";

	return 0;
}
