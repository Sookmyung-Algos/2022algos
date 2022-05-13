#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

vector<pair<int, int>> v;
int day[1001];

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second > y.second;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d, w });
	}

	sort(v.begin(), v.end(), cmp);

	int maxw = 0;
	for (int i = 0; i < n; i++) {
		int cD = v[i].first;
		int cW = v[i].second;

		for (int j = cD; j >= 1; j--) {
			if (!day[j]) {
				day[j] = 1;
				maxw += cW;
				break;
			}
		}
	}
	cout << maxw;
	return 0;
}
