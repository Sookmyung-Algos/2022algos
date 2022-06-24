#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

long long getSum3(vector<long long> v){
	int temp[4] = { 0, 1, 5, 4 };
	int temp2[4] = { 1, 5, 4, 0 };
	long long result = v[0] + v[1] + v[2];

	for (int i = 0; i < 4; i++){
		if (v[temp[i]] + v[temp2[i]] + v[3] > v[temp[i]] + v[temp2[i]] + v[2]) result = min(result, v[temp[i]] + v[temp2[i]] + v[2]);
		else result = min(result, v[temp[i]] + v[temp2[i]] + v[3]);
	}
	return result;
}

long long getSum2(vector<long long> v) {
	long long result = v[0] + v[1];

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3)) continue;
			result = min(result, v[i] + v[j]);
		}
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	vector<long long> v(6);

	for (int i = 0; i < 6; i++) cin >> v[i];

	long long sum3 = getSum3(v);
	long long sum2 = getSum2(v);
	sort(v.begin(), v.end());

	long long result = 0;

	if (n == 1) { //예외
		for (int i = 0; i < 5; i++) result += v[i];

		cout << result << "\n";
		return 0;
	}

	result += sum3 * 4;
	result += sum2 * (n - 1) * 4;
	result += sum2 * (n - 2) * 4;
	
	result += v[0] * (n - 2) * (n - 2);
	result += v[0] * (n - 2) * (n - 1) * 4;

	cout << result << "\n";
	return 0;
}
