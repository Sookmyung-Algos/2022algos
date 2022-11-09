#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[4001][4001];
string A, B;

int main()
{
	cin >> A >> B;
	dp[0][0] = 0;
	int res = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++){
			if (A[i] == B[j]) {
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}
	cout << res;
}
